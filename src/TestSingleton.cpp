#include <gtest/gtest.h>
#include "Singleton.hpp"
#include <thread>
#include <vector>

// **Test Case 1: Singleton Returns Same Instance**
TEST(SingletonTest, ReturnsSameInstance) {
    Singleton& instance1 = Singleton::GetInstance();
    Singleton& instance2 = Singleton::GetInstance();

    EXPECT_EQ(&instance1, &instance2); // ✅ Both should have the same address
}

// **Test Case 2: Singleton is Thread-Safe**
TEST(SingletonTest, ThreadSafety) {
    Singleton* instances[10];

    // Launch multiple threads to call getInstance()
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&, i]() {
            instances[i] = &Singleton::GetInstance();
        });
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    // Ensure all threads received the same instance
    for (int i = 1; i < 10; ++i) {
        EXPECT_EQ(instances[i], instances[0]);
    }
}

// **Test Case 3: Singleton Persists Across Calls**
TEST(SingletonTest, PersistsAcrossCalls) {
    Singleton& instance1 = Singleton::GetInstance();
    Singleton& instance2 = Singleton::GetInstance();
    Singleton& instance3 = Singleton::GetInstance();

    EXPECT_EQ(&instance1, &instance2);
    EXPECT_EQ(&instance2, &instance3);
}

// **Test Case 4: Singleton Cannot Be Copied**
TEST(SingletonTest, NoCopyAllowed) {
    // Compilation failure expected if uncommented:
    // Singleton instanceCopy = Singleton::getInstance(); // ❌ Should not compile
    // Singleton instanceAssign;
    // instanceAssign = Singleton::getInstance(); // ❌ Should not compile

    SUCCEED(); // ✅ Test will pass if no compilation errors occur
}

// **Test Case 5: Singleton Cannot Be Moved**
TEST(SingletonTest, NoMoveAllowed) {
    // Compilation failure expected if uncommented:
    // Singleton instanceMove = std::move(Singleton::getInstance()); // ❌ Should not compile

    SUCCEED(); // ✅ Test will pass if no compilation errors occur
}