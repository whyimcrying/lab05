#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Banking){
    Account test(0,0);
    
    ASSERT_EQ(test.GetBalance(), 0);
    
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);
    
    test.Lock();
    
    // Вызов ChangeBalance с отрицательным значением, что приведет к исключению
    ASSERT_NO_THROW(test.ChangeBalance(-100));  // Эта строка теперь вызывает ошибку
    
    ASSERT_EQ(test.GetBalance(), 100);

    ASSERT_THROW(test.Lock(), std::runtime_error);

    test.Unlock();
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);
}
