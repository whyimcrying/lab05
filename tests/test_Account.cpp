#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Banking) {
    Account test(0, 0);
    
    ASSERT_EQ(test.GetBalance(), 0);
    
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
    
    test.Lock();
    
    ASSERT_NO_THROW(test.ChangeBalance(100));  // Этот вызов проходит успешно, так как аккаунт заблокирован

    // Использование EXPECT_FATAL_FAILURE для вызова ASSERT_NO_THROW и проверки фатальной ошибки
    EXPECT_FATAL_FAILURE({
        ASSERT_NO_THROW(test.ChangeBalance(100));  // Этот вызов вызовет фатальную ошибку
    }, "Expected no exception, but got one");

    ASSERT_EQ(test.GetBalance(), 200);  // Теперь баланс увеличится, так как сумма добавлена

    ASSERT_THROW(test.Lock(), std::runtime_error);  // Проверка на выброс исключения при повторной блокировке

    test.Unlock();
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
}
