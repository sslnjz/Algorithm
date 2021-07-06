//
// Created by ssln on 2019/12/18.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

/**
 * offset_of(TYPE, MEMBER)
 *
 * @type:   The type of the structure
 * @member: The field to return the offset
 */
#define offset_of(type, member) ((size_t) &((type *)0)->member)

/**
 * sizeof_field(TYPE, MEMBER)
 *
 * @type:   The type of the structure
 * @member: The field to return the size of
 */
#define sizeof_field(type, member) (sizeof(((type*)0)->member))

/**
 * offset_of_end(TYPE, MEMBER)
 *
 * @type:   The type of the structure
 * @member: The member within the structure to get the end offset of
 */
#define offset_of_end(type, member)                       \
    (offset_of(type, member) + sizeof_field(type, member))

/**
* container_of - Cast a member of a structure out to the containing structure
* @ptr:	     The pointer to the member.
* @type:	     The type of the container struct this is embedded in.
* @member:	  The name of the member within the struct.
*
*/
#define container_of(ptr, type, member) ({                \
    void* __mptr = void* (ptr);                           \
    ((type *)(__mptr - offsetof(type, member))); })

namespace algorithm
{
    template <class T>
    struct link
    {
        link(){}
        link(const T& data) : data(data) {}

        T data;
        link* prev = nullptr, *next = nullptr;
    };

    /// <summary>
    /// Circular linked list
    /// </summary>
    /// <typeparam name="T">data base type</typeparam>
    template <class T>
    class list
    {
    public:
        list()
        {
            init_list_head();
        }

        void insert(int index, const T& data)
        {
           if(1 <= index)
           {
              int step = 1;
              auto ptr = head_ptr;
              while ((ptr = ptr->next) != head_ptr && step < index)
              {
                 ++step;
              }

              __list_add(new link<T>(data), ptr->prev, ptr);
           }
        }

        void append(const T& data)
        {
            //add tail node, the previous node of the new added node should be previoud node of head node,
            //and next node of new added node should be head node
            __list_add(new link<T> (data), head_ptr->prev, head_ptr);
        }

        void push(const T& data)
        {
            //push node, the previous node of the new node should be head node, 
            //and the tail node should be next node of head
            __list_add(new link<T> (data), head_ptr, head_ptr->next);
        }

        void pop()
        {
            //pop node, the node should be next node of head
            link<T>* ptr = head_ptr->next;
            __list_del(ptr->prev, ptr->next);

            delete ptr;
            ptr = nullptr;
        }

        void pop(link<T>* ptr)
        {
           ptr = head_ptr->next;
           __list_del(ptr->prev, ptr->next);

           ptr->prev = nullptr;
           ptr->next = nullptr;
        }

        link<T>* head() const
        {
           return head_ptr;
        }

        link<T>* tail() const
        {
           return head_ptr->prev;
        }

        void print()
        {
            for (auto ptr = head_ptr->next; ptr != head_ptr; ptr = ptr->next) {
                std::cout << ptr->data;
                if(ptr->next != head_ptr)
                    std::cout << "<-->";
            }
            std::cout << std::endl;
        }

        void reverse_print()
        {
           for (auto ptr = head_ptr->prev; ptr != head_ptr; ptr = ptr->prev)
           {
              std::cout << ptr->data;
              if (ptr->prev != head_ptr)
                 std::cout << "<-->";
           }
           std::cout << std::endl;
        }

    private:
        void init_list_head()
        {
            //Create head node
            head_ptr = new link<T>();
            head_ptr->prev = head_ptr;
            head_ptr->next = head_ptr;
        }

        /// <summary>
        /// Add a new node into nodelist
        /// </summary>
        /// <param name="node">new node</param>
        /// <param name="prev">previous node of added node</param>
        /// <param name="next">next node of added node</param>
        static void __list_add(link<T> *node, link<T> *prev, link<T> *next)
        {
            node->next = next;
            node->prev = prev;

            prev->next = node;
            next->prev = node;
        }

        /// <summary>
        /// Delete specified node
        /// </summary>
        /// <param name="prev">previous node of the deleted node</param>
        /// <param name="next">next node of the deleted node</param>
        static void __list_del(link<T> *prev, link<T> *next)
        {
            next->prev = prev;
            prev->next = next;
        }

    private:
        link<T> * head_ptr = nullptr;
    };

}

#endif //ALGORITHM_LIST_H
