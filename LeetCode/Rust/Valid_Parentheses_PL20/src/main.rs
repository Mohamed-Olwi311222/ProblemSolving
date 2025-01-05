/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

 

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

use std::vec;

pub fn is_valid(s: String) -> bool {
    let mut vect: Vec<char> = Vec::new();
    if s.as_bytes().len() == 0 || s.as_bytes().len() == 1
    {
        false
    }
    else {
         for item in s.chars() {
            match item {
                '}'=> { 
                    if vect.pop() != Some('{'){
                        return false;
                    }
                }
                ']'=> { 
                    if vect.pop() != Some('['){
                        return false;
                    }
                }
                ')'=> { 
                    if vect.pop() != Some('('){
                        return false;
                    }
            }
            _=> vect.push(item)
        }
        }
        vect.is_empty()
    }
    }
