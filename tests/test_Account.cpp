#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Banking) {
    Account test(0, 0);
    
    ASSERT_EQ(test.GetBalance(), 0);
    
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
    
    test.Lock();
    
    ASSERT_NO_THROW(test.ChangeBalance(50));  // Проверка на успешное изменение баланса с суммой <= 50
    ASSERT_EQ(test.GetBalance(), 50);

    // Этот вызов вызовет исключение, так как сумма превышает 50
    ASSERT_NO_THROW(test.ChangeBalance(100));  // Ожидается выброс исключения, тест выдаст ошибку

    ASSERT_EQ(test.GetBalance(), 100);

    ASSERT_THROW(test.Lock(), std::runtime_error);  // Проверка на выброс исключения при повторной блокировке

    test.Unlock();
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
}
