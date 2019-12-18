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
#define offset_of(type, member)     ((size_t) &((type *)0)->member)

/**
 * sizeof_field(TYPE, MEMBER)
 *
 * @type:   The type of the structure
 * @member: The field to return the size of
 */
#define sizeof_field(type, member)  (sizeof(((type*)0)->member))

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
* @ptr:	         The pointer to the member.
* @type:	     The type of the container struct this is embedded in.
* @member:	     The name of the member within the struct.
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


    template <class T>
    class list
    {
    public:
        list()
        {
            init_list_head();
        }

        void append(const T& data)
        {
            __list_add(new link<T> (data), head_ptr->prev, head_ptr);
        }

        void push(const T& data)
        {
            __list_add(new link<T> (data), head_ptr, head_ptr->next);
        }

        void pop()
        {
            link<T>* ptr = head_ptr->next;
            __list_del(head_ptr, head_ptr->next->next);

            delete ptr;
            ptr = nullptr;
        }

        void print()
        {
            for (link<T>* ptr = head_ptr->next; ptr != head_ptr; ptr = ptr->next) {
                std::cout << ptr->data;
                if(ptr->next != head_ptr)
                    std::cout << "<-->";
            }
            std::cout << std::endl;
        }

    private:
        void init_list_head()
        {
            head_ptr = new link<T>();
            head_ptr->prev = head_ptr;
            head_ptr->next = head_ptr;
        }

        void __list_add(link<T> *node, link<T> *prev, link<T> *next)
        {
            next->prev = node;
            node->next = next;
            node->prev = prev;
            prev->next = node;
        }

        void __list_del(link<T> *prev, link<T> *next)
        {
            next->prev = prev;
            prev->next = next;
        }

    private:
        link<T> * head_ptr = nullptr;
    };

}

#endif //ALGORITHM_LIST_H
