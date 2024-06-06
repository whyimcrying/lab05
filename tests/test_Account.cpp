#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Banking) {
    Account test(0, 0);
    
    ASSERT_EQ(test.GetBalance(), 0);
    
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
    
    test.Lock();
    
    ASSERT_NO_THROW(test.ChangeBalance(50));  // Проверка на успешное изменение баланса с суммой <= 50
    ASSERT_EQ(test.GetBalance(), 50);
    
    try {
        test.ChangeBalance(100);
        FAIL() << "Expected std::runtime_error";  // Этот вызов должен обязательно сработать
    } catch (std::runtime_error const &err) {
        EXPECT_EQ(err.what(), std::string("Account is not locked"));  // Это не произойдет, поскольку тест заблокирован
    } catch (...) {
        FAIL() << "Expected std::runtime_error";  // Ловим любое другое исключение и выдаем ошибку
    }

    ASSERT_EQ(test.GetBalance(), 150);  // Теперь баланс увеличится, так как сумма добавлена

    ASSERT_THROW(test.Lock(), std::runtime_error);  // Проверка на выброс исключения при повторной блокировке

    test.Unlock();
    ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);  // Проверка на выброс исключения при незаблокированном аккаунте
}
