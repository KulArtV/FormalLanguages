[![Build Status](https://travis-ci.com/KulArtV/FormalLanguages.svg?token=hkLCKRKpQ7j6SltOFRPuww&branch=FirstPrac)]
(https://travis-ci.com/KulArtV/FormalLanguages)

# What can you find here?

In this branch you can find the solution to the first practical
task on formal languages.

## What task is?
You need to write a program that, given a regular expression in 
 inverted Polish notation, finds the length of the shortest word, 
 what contains *k* letters *x*.

## How to solve?
First of all, we need a stack of *states*. 
 *State* - is vector, where on m-th position we will put minimal 
 length of word, what is OK for regexp and contains *k* letters *x*.
 By default, state contains *k + 1* INF elements.

Let's move from the first symbol to the last one by one. In given 
 regular expression it's possible to find letters from *a, b, c* 
 alphabet, *+*, *.* and *\** symbols. 

* If next symbol is letter, let's push new state for word with one 
  letter on stack.

* If next symbol is *+*, let's get two top states (and pop it) 
  from stack and Merge it. Result of merging is state, on each 
  position of it is minimum of two elements from this position from 
  popped states. Then push result state on stack.

* If next symbol is *.* , let's concatenate (Append method) two top
  states. How to find *'m-th'* element of resulting state? If we will 
  find minimum of sums of pair, where the first element of pair is 
  *'i-th'* element of first state and another one is *(m - i) th*
  element of second one. Therefore, in loop we can find each element
  of resulting state, or in extern loop find concatenating result.

* If next symbol is *\**, let's make it's closure. It isn't hard
  to understand, that closure of *'U'* word is disjunction 
  (*+* operation) of words like *U, UU, UUU, ..., U(k times)*. 

As a result, after we will reach the end of given expression, we 
 will have in stack of result only one, *'final'* state, and the last
 element of this state is the answer.

If it is impossible to make an operation (stack contains not enough 
 operands for it) or after reaching the end of expression there is 
 more than one state in stack, given expression is incorrect and you
 will find *ERROR* message as a result of programm.

## Complexity of solution
Each operation takes *O(k)* memory and at one moment at the worst
 case stack takes *O(k \* L)* memory, where *L* - length of 
 given expression.

Operation of disjunction or adding letter takes *O(k)* time. 
 Concatenation takes *O(k^2)* time and Closure takes *O(k^3)* time,
 so at the worst case time complexity is *O(L * k^3)*.

