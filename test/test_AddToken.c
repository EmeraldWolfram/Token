#include "unity.h"
#include "AddToken.h"
#include "mock_Token.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *  With mocking method, the functions createIntegerToken & createOperatorToken
 *  were compilable and called in this test
 *  
 *  add2Tokens should be able to connect two Integer Tokens to into the Token tree
 *
 *  Eg, Given two integer tokens with value 2 and 3 respectively should return the
 *  following token tree
 *
 *    +
 *   / \
 *  2   3
 *
 *
 */

void setUp(void){}

void tearDown(void){}

void test_add2Tokens_given_2_ADD_3_should_return_Tokens_Tree_with_value(void){
  IntegerToken* leftTk      = malloc(sizeof(IntegerToken));
  IntegerToken* rightTk     = malloc(sizeof(IntegerToken));
  OperatorToken* addToken   = malloc(sizeof(OperatorToken)+(sizeof(Token*))*2);   
  
  leftTk->type      = TOKEN_INTEGER_TYPE;
  rightTk->type     = TOKEN_INTEGER_TYPE;
  leftTk->value     = 2;
  rightTk->value    = 3;
  addToken->type    = TOKEN_OPERATOR_TYPE;
  addToken->symbol  = "+";
  addToken->arity   = INFIX;
  addToken->assoc   = LEFT_TO_RIGHT;

  createIntegerToken_ExpectAndReturn(2,leftTk);
  createIntegerToken_ExpectAndReturn(3,rightTk);    
  createOperatorToken_ExpectAndReturn("+", INFIX, LEFT_TO_RIGHT, addToken);

  addToken = (OperatorToken*)add2Tokens(2,"+",3);
  
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,addToken->token[0]->type);
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE,addToken->token[1]->type);
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE,addToken->type);
  
  TEST_ASSERT_EQUAL_PTR(leftTk,(IntegerToken*)addToken->token[0]);
  TEST_ASSERT_EQUAL_PTR(rightTk,(IntegerToken*)addToken->token[1]);
  
  TEST_ASSERT_EQUAL("+",addToken->symbol);
  TEST_ASSERT_EQUAL(INFIX,addToken->arity);
  TEST_ASSERT_EQUAL(LEFT_TO_RIGHT,addToken->assoc);
 
  TEST_ASSERT_EQUAL(2,((IntegerToken*)addToken->token[0])->value);
  TEST_ASSERT_EQUAL(3,((IntegerToken*)addToken->token[1])->value);
}




