/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#include "../../Testing/comparators.h"
#include "../inc/array.h"

int main(void) {
  START_TEST("array_test");

  array arr = new_array();

  delete_array(arr);
  // len should not be >= INT_MAX.
  const size_t len = 5;
  const int last_element = len - 1;
  const int first_element = 0;
  linked_list* list = new_linked_list(first_element);

  for (int i = first_element + 1; i <= last_element; ++i) {
    add_to_linked_list(list, i);
  }

  EXPECT_TRUE(exist_in_linked_list(list, first_element + 2));
  EXPECT_FALSE(exist_in_linked_list(list, last_element + 1));
  EXPECT_EQUAL(list->size, len);

  linked_list* list_copy = copy_linked_list(list);

  EXPECT_TRUE(equal_linked_list(list, list));
  EXPECT_TRUE(equal_linked_list(list, list_copy));
  reverse_linked_list(list);
  EXPECT_FALSE(equal_linked_list(list, list_copy));
  reverse_linked_list(list_copy);
  EXPECT_TRUE(equal_linked_list(list, list_copy));
  EXPECT_TRUE(equal_linked_list(list_copy, list_copy));

  erase_single_match_linked_list(list_copy, 3);
  EXPECT_FALSE(exist_in_linked_list(list_copy, 3));
  EXPECT_FALSE(equal_linked_list(list, list_copy));

  linked_list_node* node;
  int curr_element = last_element;

  for (node = list->head; node != NULL; node = node->next) {
    EXPECT_EQUAL(node->value, curr_element--);
  }

  delete_linked_list(list);
  delete_linked_list(list_copy);

  FINISH_TEST();

  return 0;
}
