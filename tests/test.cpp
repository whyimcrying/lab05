#include <Account.h>
#include <Transaction.h>
#include <gtest/gtest.h>

TEST(Banking, Account) {
  Account some_bal(0,0);
  
  EXPECT_EQ(some_bal.GetBalance(), 0);
  
  EXPECT_THROW(some_bal.ChangeBalance(123), std::runtime_error);
  
  some_bal.Lock();
  
  some_bal.ChangeBalance(123);
  EXPECT_EQ(some_bal.GetBalance(), 123);
  
  EXPECT_THROW(some_bal.Lock(), std::runtime_error);
}

TEST(Banking, Transaction) {
  int some_money = 5000, some_more_money = 0, fee = 100;
  
  Account rich(0,some_money), poor(1,some_more_money);
  Transaction transaction;

  EXPECT_EQ(transaction.fee(), 1);

  transaction.set_fee(fee);

  EXPECT_EQ(transaction.fee(), fee);

  EXPECT_THROW(transaction.Make(rich, rich, 1), std::logic_error);
  EXPECT_THROW(transaction.Make(rich, poor, -1), std::invalid_argument);
  EXPECT_THROW(transaction.Make(rich, poor, 99), std::logic_error);

  EXPECT_EQ(transaction.Make(rich, poor, 150), false);

  EXPECT_EQ(transaction.Make(rich, poor, 1000), true);
  EXPECT_EQ(poor.GetBalance(), 1000); 
  EXPECT_EQ(rich.GetBalance(), 3900);

  EXPECT_EQ(transaction.Make(rich, poor, 3900), false);
  
  EXPECT_EQ(poor.GetBalance(), 1000); 
  EXPECT_EQ(rich.GetBalance(), 3900);
}
