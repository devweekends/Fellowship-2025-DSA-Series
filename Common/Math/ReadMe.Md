## Mathemetics Basics:

### modulo

modulo operator (%) returns the remainder of a division operation. For example, the expression 26 % 5 would return 1, because 26 divided by 5 is 5 with a remainder of 1.

So in your example, 5 modulo 26 would also return 5, because 5 cannot be divided by 26 evenly, and the remainder is 5. Therefore, the expression 5 % 26 would evaluate to 5.

# Mathemetical Techniques:

### why not do left + right / 2 ? what's the benefit for  left + (right - left) / 2 ? explain with example

The reason we use left + (right - left) / 2 instead of left + right / 2 is to avoid an integer overflow when computing the middle index.

Let's take the example:
arr = [1, 3, 4, 6, 7, 9, 11, 13]

Suppose we want to compute the middle index of the subarray defined by left = 0 and right = 7 using the expression left + right / 2.

In this case, left is 0 and right is 7, so the middle index is computed as:
mid = 0 + 7 / 2 = 3

This gives us the correct middle index, which is 3.

However, suppose we want to compute the middle index of a subarray with a very large left and right, such as:

left = 2147483640
right = 2147483647

If we use the expression left + right / 2, we get:
``` mid = 2147483640 + 2147483647 / 2 = 4294967283 ```

This result overflows the range of a 32-bit integer, which causes a runtime error in our program.

To avoid this problem, we can use the expression left + (right - left) / 2 instead. This expression is mathematically equivalent to left + right / 2, but it avoids the integer overflow problem.

In the same example, if we use the expression left + (right - left) / 2, we get:
``` mid = 2147483640 + (2147483647 - 2147483640) / 2 = 2147483643 ```

This result is within the range of a 32-bit integer, and gives us the correct middle index.

So, in summary, we use left + (right - left) / 2 instead of left + right / 2 to avoid an integer overflow when computing the middle index of a subarray with a large range of indices.