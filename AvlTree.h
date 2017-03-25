        #ifndef _AVL_TREE_H_
        #define _AVL_TREE_H_

        #include "dsexceptions.h"
#include <stdlib.h> // for NULL
          // Node and forward declaration because g++ does
          // not understand nested classes.
        template <class Comparable>
        class AvlTree;

        template <class Comparable>
        class AvlNode
        {
            Comparable element;
            AvlNode   *left;
            AvlNode   *right;
            int        height;

            AvlNode(  Comparable & theElement, AvlNode *lt, AvlNode *rt, int h = 0 )
              : element( theElement ), left( lt ), right( rt ), height( h ) { }
            friend class AvlTree<Comparable>;
        };


        // AvlTree class
        //
        // RUCTION: with ITEM_NOT_FOUND object used to signal failed finds
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // void remove( x )       --> Remove x (unimplemented)
        // Comparable find( x )   --> Return item that matches x
        // Comparable findMin( )  --> Return smallest item
        // Comparable findMax( )  --> Return largest item
        // boolean isEmpty( )     --> Return true if empty; else false
        // void makeEmpty( )      --> Remove all items
        // void printTree( )      --> Print tree in sorted order

        template <class Comparable>
        class AvlTree
        {
          public:
            explicit AvlTree(  Comparable & notFound );
            AvlTree(  AvlTree & rhs );
            ~AvlTree( );

             Comparable & findMin( ) ;
             Comparable & findMax( ) ;
             Comparable & find(  Comparable & x ) ;
            bool isEmpty( ) ;
            void printTree( ) ;

            void makeEmpty( );
            void insert(  Comparable & x );
            void remove(  Comparable & x );

             AvlTree & operator=(  AvlTree & rhs );

          private:
            AvlNode<Comparable> *root;
             Comparable ITEM_NOT_FOUND;

             Comparable & elementAt( AvlNode<Comparable> *t ) ;

            void insert(  Comparable & x, AvlNode<Comparable> * & t ) ;
            void remove(  Comparable & x, AvlNode<Comparable> * & t) ;
            AvlNode<Comparable> * findMin( AvlNode<Comparable> *t ) ;
            AvlNode<Comparable> * findMax( AvlNode<Comparable> *t ) ;
            AvlNode<Comparable> * find(  Comparable & x, AvlNode<Comparable> *t ) ;
            void makeEmpty( AvlNode<Comparable> * & t ) ;
            void printTree( AvlNode<Comparable> *t ) ;
            AvlNode<Comparable> * clone( AvlNode<Comparable> *t ) ;

                // Avl manipulations
            int height( AvlNode<Comparable> *t ) ;
            int max( int lhs, int rhs ) ;
            void rotateWithLeftChild( AvlNode<Comparable> * & k2 ) ;
            void rotateWithRightChild( AvlNode<Comparable> * & k1 ) ;
            void doubleWithLeftChild( AvlNode<Comparable> * & k3 ) ;
            void doubleWithRightChild( AvlNode<Comparable> * & k1 ) ;
        };

        #include "AvlTree.cpp"
        #endif
