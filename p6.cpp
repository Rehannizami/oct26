#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

/*
 ============================================================================
  oct26 / p6.cpp
  CODING CHALLENGE: Generic Circular Ring Buffer (ArrayDeque Foundation)
 ============================================================================
  Context from oct26/README.md:
  - In Chapter 2 ("Array-based lists"), normal vectors/arrays take O(n) time
    to remove from the front because all remaining elements must shift.
  - An ArrayDeque solves this by using a circular array with modular arithmetic:
      index = (head + i) % capacity
    This allows O(1) push and O(1) pop operations without shifting elements!

 ============================================================================
  Problem Statement:
  Implement a generic, fixed-capacity circular ring buffer class:
      template <typename T>
      class CircularBuffer;

  Requirements to Implement:
  1. Constructor:
     - CircularBuffer(size_t capacity)
     - Initializes buffer with the specified fixed capacity.
  
  2. Status Queries:
     - size_t size() const       : Returns current number of elements stored.
     - size_t capacity() const   : Returns the maximum capacity.
     - bool isEmpty() const      : Returns true if buffer contains 0 elements.
     - bool isFull() const       : Returns true if size() == capacity.

  3. Core Queue Operations:
     - bool push(const T& item)  :
       If buffer is full, return false (do not insert).
       Otherwise, store item at `tail`, update tail via (tail + 1) % capacity,
       increment count, and return true.

     - bool pop(T& outItem)      :
       If buffer is empty, return false.
       Otherwise, retrieve element at `head`, update head via (head + 1) % capacity,
       decrement count, and return true.

     - bool peek(T& outItem) const :
       If buffer is empty, return false.
       Otherwise, set outItem to element at `head` without removing it, and return true.

  4. Random Access (from README.md ArrayDeque):
     - bool get(size_t index, T& outItem) const :
       If index >= size(), return false.
       Otherwise, fetch element at circular index ((head + index) % capacity)
       and return true.

 ============================================================================
  How to Compile and Run:
  In terminal:
    $env:PATH = "C:\msys64\ucrt64\bin;$env:PATH"
    g++ -std=c++17 p6.cpp -o p6.exe
    .\p6.exe
 ============================================================================
*/

// Retro Terminal Text Animator
void typeText(const std::string& text, int delayMs = 25) {
    for (char ch : text) {
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

// ============================================================================
// TEMPLATE CLASS: CircularBuffer<T>
// ============================================================================
template <typename T>
class CircularBuffer {
private:
    std::vector<T> data;
    size_t cap;
    size_t head;
    size_t tail;
    size_t count;

public:
    // TODO 1: Constructor
    explicit CircularBuffer(size_t capacity)
        : data(capacity), cap(capacity), head(0), tail(0), count(0) {
        // Ready for use
    }

    // TODO 2: Query methods
    size_t size() const {
        // TODO: Return current number of elements
        return count;
    }

    size_t capacity() const {
        // TODO: Return maximum capacity
        return cap;
    }

    bool isEmpty() const {
        // TODO: Return true if count is 0
        return count == 0;
    }

    bool isFull() const {
        // TODO: Return true if count equals capacity
        return count == cap;
    }

    // TODO 3: Push an item to the back (tail)
    bool push(const T& item) {
        if (isFull()) {
            return false;
        }

        // TODO: Store `item` at `tail`
        // TODO: Advance `tail = (tail + 1) % cap`
        // TODO: Increment `count`
        // TODO: Return true

        return false; // Replace with your logic
    }

    // TODO 4: Pop the oldest item from the front (head)
    bool pop(T& outItem) {
        if (isEmpty()) {
            return false;
        }

        // TODO: Assign `outItem = data[head]`
        // TODO: Advance `head = (head + 1) % cap`
        // TODO: Decrement `count`
        // TODO: Return true

        return false; // Replace with your logic
    }

    // TODO 5: Peek at the oldest item without removing it
    bool peek(T& outItem) const {
        if (isEmpty()) {
            return false;
        }

        // TODO: Assign `outItem = data[head]` and return true

        return false; // Replace with your logic
    }

    // TODO 6: Random access relative to head: get(0) is head, get(1) is next, etc.
    bool get(size_t index, T& outItem) const {
        if (index >= count) {
            return false;
        }

        // TODO: Calculate real index = (head + index) % cap
        // TODO: Assign `outItem = data[realIndex]` and return true

        return false; // Replace with your logic
    }

    // Optional utility: Print the buffer state
    void printDebug() const {
        std::cout << "[Buffer Debug] Count: " << count << "/" << cap
                  << " | Head: " << head << " | Tail: " << tail << " | Elements: [ ";
        for (size_t i = 0; i < count; ++i) {
            std::cout << data[(head + i) % cap] << " ";
        }
        std::cout << "]\n";
    }
};

// ============================================================================
// AUTOMATED TEST SUITE
// ============================================================================
void runTests() {
    int passed = 0;
    int total = 5;

    std::cout << "\n=================================================" << std::endl;
    std::cout << "           RUNNING AUTOMATED TEST SUITE          " << std::endl;
    std::cout << "=================================================" << std::endl;

    // --- TEST 1: Basic Push, Peek & Pop (FIFO Order) ---
    {
        std::cout << "\n[Test 1] Basic Push, Peek and Pop (FIFO)... ";
        CircularBuffer<int> buf(3);
        bool ok = true;

        ok = ok && (buf.isEmpty() == true);
        ok = ok && buf.push(10);
        ok = ok && buf.push(20);
        ok = ok && (buf.size() == 2);

        int val = 0;
        ok = ok && buf.peek(val) && (val == 10); // Oldest is 10
        ok = ok && buf.pop(val) && (val == 10);
        ok = ok && buf.pop(val) && (val == 20);
        ok = ok && (buf.isEmpty() == true);

        if (ok) {
            std::cout << "\033[32m[PASS]\033[0m\n";
            passed++;
        } else {
            std::cout << "\033[31m[FAIL]\033[0m\n";
        }
    }

    // --- TEST 2: Circular Wrap-Around ---
    {
        std::cout << "[Test 2] Circular Index Wrap-Around... ";
        CircularBuffer<int> buf(3);
        bool ok = true;

        buf.push(1);
        buf.push(2);
        buf.push(3);

        int val = 0;
        buf.pop(val); // removes 1, head advances to 1
        buf.pop(val); // removes 2, head advances to 2

        // Now push two more: tail must wrap around to index 0 and 1!
        ok = ok && buf.push(4);
        ok = ok && buf.push(5);
        ok = ok && (buf.size() == 3);

        // Should pop: 3, 4, 5
        ok = ok && buf.pop(val) && (val == 3);
        ok = ok && buf.pop(val) && (val == 4);
        ok = ok && buf.pop(val) && (val == 5);
        ok = ok && buf.isEmpty();

        if (ok) {
            std::cout << "\033[32m[PASS]\033[0m\n";
            passed++;
        } else {
            std::cout << "\033[31m[FAIL]\033[0m\n";
        }
    }

    // --- TEST 3: Full Buffer Capacity Guard ---
    {
        std::cout << "[Test 3] Full Capacity Boundary Protection... ";
        CircularBuffer<int> buf(2);
        bool ok = true;

        ok = ok && buf.push(100);
        ok = ok && buf.push(200);
        ok = ok && buf.isFull();
        ok = ok && (buf.push(300) == false); // Must reject when full!
        ok = ok && (buf.size() == 2);

        if (ok) {
            std::cout << "\033[32m[PASS]\033[0m\n";
            passed++;
        } else {
            std::cout << "\033[31m[FAIL]\033[0m\n";
        }
    }

    // --- TEST 4: Empty Buffer Underflow Guard ---
    {
        std::cout << "[Test 4] Empty Buffer Underflow Protection... ";
        CircularBuffer<int> buf(2);
        bool ok = true;

        int val = -1;
        ok = ok && (buf.pop(val) == false);  // Must reject pop when empty
        ok = ok && (buf.peek(val) == false); // Must reject peek when empty

        if (ok) {
            std::cout << "\033[32m[PASS]\033[0m\n";
            passed++;
        } else {
            std::cout << "\033[31m[FAIL]\033[0m\n";
        }
    }

    // --- TEST 5: Generic Types & Random Access get(i) ---
    {
        std::cout << "[Test 5] Generic std::string & get(i) Random Access... ";
        CircularBuffer<std::string> strBuf(4);
        bool ok = true;

        strBuf.push("Task A");
        strBuf.push("Task B");
        strBuf.push("Task C");

        std::string item;
        strBuf.pop(item); // pops "Task A"
        strBuf.push("Task D");

        // Remaining elements relative to head: [0] -> Task B, [1] -> Task C, [2] -> Task D
        ok = ok && strBuf.get(0, item) && (item == "Task B");
        ok = ok && strBuf.get(1, item) && (item == "Task C");
        ok = ok && strBuf.get(2, item) && (item == "Task D");
        ok = ok && (strBuf.get(3, item) == false); // Out of bounds

        if (ok) {
            std::cout << "\033[32m[PASS]\033[0m\n";
            passed++;
        } else {
            std::cout << "\033[31m[FAIL]\033[0m\n";
        }
    }

    std::cout << "\n-------------------------------------------------" << std::endl;
    std::cout << "Test Summary: " << passed << " / " << total << " tests passed." << std::endl;
    if (passed == total) {
        std::cout << "\033[32mCONGRATULATIONS! All tests passed successfully!\033[0m\n";
    } else {
        std::cout << "\033[33mKeep going! Implement the // TODO methods to pass remaining tests.\033[0m\n";
    }
    std::cout << "=================================================\n" << std::endl;
}

// ============================================================================
// MAIN ENTRY POINT
// ============================================================================
int main() {
    typeText("\033[36mInitializing oct26 / p6.cpp environment...\n\033[0m", 30);
    typeText("\033[32mAccess granted: Circular Ring Buffer Challenge.\n\033[0m", 30);

    const char spinner[] = {'|', '/', '-', '\\'};
    for (int i = 0; i < 16; ++i) {
        std::cout << "\rLoading test harness " << spinner[i % 4] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
    std::cout << "\rReady!                                    \n";

    runTests();

    return 0;
}
