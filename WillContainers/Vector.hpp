//
//  Vector.hpp
//  WillContainers
//
//  Created by Julien Esposito on 8/24/16.
//  Copyright © 2016 Julien Esposito. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <iostream>

//
//  Vector.cpp
//  WillContainers
//
//  Created by Julien Esposito on 8/24/16.
//  Copyright © 2016 Julien Esposito. All rights reserved.
//

/******************************************************************************/
/******************************************************************************/

#include "Vector.hpp"
#include <iostream>

/******************************************************************************/
/******************************************************************************/
typedef enum _Vector_Exception
{
    VE_OutOfRange = 0,
    VE_None
} Vector_Exception;

/******************************************************************************/
/******************************************************************************/
template <class T> class Vector
{
public:
    /******************************************************************************/
    /******************************************************************************/
    void push_back( const T& element )
    {
        // the number of elements before adding a new value
        size_t old_num_elements = m_number_elements;
        
        // next, we create a variable which hold the new number
        // of elements
        size_t new_num_elements = m_number_elements + 1;
        m_number_elements = new_num_elements;
        // if the internal capacity, is less or equal
        if( m_capacity <= new_num_elements )
        {
            size_t new_capacity = new_num_elements + DEFAULT_CAPACITY;
            m_capacity = new_capacity;
            // if the internal pointer has already been allocated
            if( nullptr != m_internal_array )
            {
                
                // create a save vector to save the internal array
                T* temp = new T[ m_capacity ];

                // save the internal array
                for( size_t i = 0; i < m_number_elements; i++ )
                    temp[ i ] = m_internal_array[ i ];
                
                // delete the internal array;
                delete [  ] m_internal_array;
                
                //m_capacity = new_capacity;
                
                m_internal_array = new T[ m_capacity ];
                
                for( size_t i = 0; i < old_num_elements; i++ )
                {
                    m_internal_array[ i ] = temp[ i ];
                }
            } // End of IF the internal pointer has already been alocates
            else { // if the internal pointer has not been already allocated
                size_t new_capacity = new_num_elements + DEFAULT_CAPACITY;
                m_capacity = new_capacity;
                m_internal_array = new T[ m_capacity ];
            }
        }
        
        m_internal_array[ m_number_elements - 1 ] = element;
        return;
    }
    
    /******************************************************************************/
    /******************************************************************************/
    Vector< T >( void )
    {
        m_internal_array = nullptr;
        m_capacity = 0;
        m_number_elements = 0;
    }
    
    /******************************************************************************/
    /******************************************************************************/
    Vector< T >( const Vector< T >& rhs )
    {
        m_capacity = rhs.m_capacity;
        m_number_elements = rhs.m_number_elements;
        m_internal_array = new T[ m_capacity ];
        memcpy( m_internal_array, rhs.m_internal_array, m_capacity * sizeof( T ) );
    }
    
    /******************************************************************************/
    /******************************************************************************/
    T& operator[]( size_t index ){
//        if( index < 0 || index > m_capacity - 1 ) {
//            throw VE_OutOfRange;
//        }
        return m_internal_array[ index ];
    }
    
    /******************************************************************************/
    /******************************************************************************/
    T& operator+=( const Vector< T >& rhs )
    {
        size_t numberElementsToAllocate = rhs.m_number_elements + m_number_elements;
        T* temp = new T[ numberElementsToAllocate ];
        memcpy( temp, m_internal_array, sizeof( T ) * m_number_elements );
        memcpy( &temp[ m_number_elements - 1 ], rhs.m_internal_array, sizeof( T ) * rhs.m_number_elements );
        delete m_internal_array;
        m_internal_array = nullptr;
        m_capacity = numberElementsToAllocate + DEFAULT_CAPACITY;
        m_internal_array = new T[ m_capacity ];
        delete [  ] temp;
        temp = nullptr;
    }
    /******************************************************************************/
    /******************************************************************************/
    void Clear( void )
    {
        delete [  ] m_internal_array;
        m_internal_array = nullptr;
        m_capacity = 0;
        m_number_elements = 0;
        return;
    }
    
    /******************************************************************************/
    /******************************************************************************/
    void _PrintInfo( void )
    {
        std::cout << "Capacity = " << m_capacity << std::endl;
        std::cout << "Number of Elements = " << m_number_elements << std::endl;
        return;
    }
    
    /******************************************************************************/
    /******************************************************************************/
    friend std::ostream& operator<<( std::ostream& o, const Vector< T >& rhs )
    {
        for( size_t i = 0; i < rhs.m_number_elements; i++ ) {
            o << rhs.m_internal_array[ i ] << " ";
        }
        o << std::endl;
        return o;
    }
    /******************************************************************************/
    /******************************************************************************/
    T& operator=( const Vector< T >& rhs )
    {
        Clear(  );
        m_capacity = rhs.m_capacity;
        m_number_elements = rhs.m_number_elements;
        m_internal_array = new T[ m_capacity ];
        m_number_elements = rhs.m_number_elements;
        memcpy( m_internal_array, rhs.m_internal_array, sizeof( T ) * m_capacity );
        return *this;
    }
    
    /******************************************************************************/
    /******************************************************************************/
    Vector < T >( const size_t capacity )
    {
        m_capacity = capacity;
        m_number_elements = 0;
        m_internal_array = new T[ m_capacity ];
    }
    
    /******************************************************************************/
    /******************************************************************************/
    virtual ~Vector< T >( void )
    {
        Clear(  );
    }
    
protected:
    T* m_internal_array;
    size_t m_capacity;
    size_t m_number_elements;
    
public:
    static const size_t DEFAULT_CAPACITY = 64;
    
};

#endif /* Vector_hpp */
