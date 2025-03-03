// Copyright 2024 Ramzan Kamaletdinov

#ifndef MERGE_SORTED_LISTS_H_
#define MERGE_SORTED_LISTS_H_

#include "../lib_List/List.h"

template<typename T>
List<T> mergeSortedLists(List<T>& list1, List<T>& list2) {
    List<T> result;

    typename List<T>::Node* current1 = list1.head;
    typename List<T>::Node* current2 = list2.head;

    while (current1 && current2) {
        if (current1->data < current2->data) {
            result.append(current1->data);
            current1 = current1->next;
        }
        else {
            result.append(current2->data);
            current2 = current2->next;
        }
    }

    // Добавляем оставшиеся элементы
    while (current1) {
        result.append(current1->data);
        current1 = current1->next;
    }

    while (current2) {
        result.append(current2->data);
        current2 = current2->next;
    }

    return result;
}

#endif  // MERGE_SORTED_LISTS_H_

