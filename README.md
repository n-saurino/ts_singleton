# Implement a Thread-Safe Singleton

## Problem Description

Design and implement a thread-safe singleton class in C++. The singleton pattern ensures that only one instance of a class is created and provides a global access point to that instance. The implementation must be both efficient and thread-safe, preventing multiple threads from creating separate instances.

## Core Requirements

### 1. Instance Management
- Single instance creation and management
- Global access point to the instance
- Lazy initialization (create on first use)

### 2. Thread Safety
- Safe concurrent access from multiple threads
- Prevention of multiple instance creation
- Protection against race conditions

### 3. Memory Management
- Proper cleanup on program termination
- No memory leaks
- Resource management

## Interface Requirements

```cpp
class Singleton {
public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    // Global access point
    static Singleton* getInstance();
    
    // Optional: Cleanup method
    static void cleanup();

private:
    // Private constructor to prevent direct instantiation
    Singleton();
    
    // Single instance pointer
    static Singleton* instance;
};
```

## Technical Constraints

### Thread Safety Requirements
1. Safe initialization during first access
2. Thread-safe access to existing instance
3. Protection against concurrent initialization
4. Prevention of race conditions

### Performance Requirements
1. Minimal overhead for instance access
2. Efficient locking mechanisms
3. Quick instance retrieval after initialization
4. Optimal memory usage

### Memory Management Requirements
1. Proper cleanup of resources
2. No memory leaks
3. Safe destruction sequence
4. Resource cleanup on program termination

## Implementation Approaches

### 1. Basic Double-Checked Locking
```cpp
class Singleton {
    static std::mutex mutex_;
    static Singleton* instance;
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
```

### 2. Modern C++ Approach (C++11 and later)
```cpp
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};
```

## Follow-Up Considerations

### 1. Performance Optimization
- Double-checked locking pattern
- Memory barriers and synchronization
- Lock-free techniques
- Cache-friendly implementation

### 2. Memory Management
- Smart pointer usage
- Static initialization
- Cleanup strategies
- Resource management patterns

### 3. Testing Considerations
- Concurrent access testing
- Memory leak detection
- Performance benchmarking
- Edge case handling

## Best Practices

1. Use of RAII principles
2. Proper synchronization mechanisms
3. Exception safety
4. Resource cleanup
5. Documentation of thread safety guarantees

## Example Usage

```cpp
// Access the singleton instance
Singleton* instance1 = Singleton::getInstance();
Singleton* instance2 = Singleton::getInstance();

// Verify single instance
assert(instance1 == instance2);

// Multiple thread access
std::thread t1([]() {
    Singleton* instance = Singleton::getInstance();
    // Use instance...
});

std::thread t2([]() {
    Singleton* instance = Singleton::getInstance();
    // Use instance...
});

t1.join();
t2.join();
```

## Performance Benchmarking

Key metrics to measure:
1. Instance creation time
2. Access latency
3. Memory usage
4. Thread contention
5. Cache performance

## Common Pitfalls to Avoid

1. Race conditions in initialization
2. Memory leaks in cleanup
3. Unnecessary synchronization
4. Incorrect destruction order
5. Dead locks in multi-threaded access
