// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "../src/Queue.h"
#include <gtest/gtest.h>

namespace {
// To use a test fixture, derive a class from testing::Test.
class QueueTest : public testing::Test {
protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.

    void SetUp() override {
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    //
    // virtual void TearDown() {
    // }

    // A helper function that some test uses.
    static int Double(int n) {
        return 2*n;
    }

    // A helper function for testing Queue::Map().
    void MapTester(const Queue<int> * q) {
        // Creates a new queue, where each element is twice as big as the
        // corresponding one in q.
        const Queue<int> * const new_q = q->Map(Double);

        // Verifies that the new queue has the same size as q.
        ASSERT_EQ(q->Size(), new_q->Size());

        // Verifies the relationship between the elements of the two queues.
        for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head(); n1 != nullptr; 
          n1 = n1->next(), n2 = n2->next()) {
            EXPECT_EQ(2 * n1->element(), n2->element());
        }

        delete new_q;
    }

    // Declares the variables your tests want to use.
    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};

// Tests the default c'tor.
TEST_F(QueueTest, DefaultConstructor) {
  // You can access data in the test fixture here.
  EXPECT_EQ(0u, q0_.Size());
}

// Tests Dequeue().
TEST_F(QueueTest, Dequeue) {
    int * n = q0_.Dequeue();
    EXPECT_TRUE(n == nullptr);

    n = q1_.Dequeue();
    ASSERT_TRUE(n != nullptr);
    EXPECT_EQ(1, *n);
    EXPECT_EQ(0u, q1_.Size());
    delete n;

    n = q2_.Dequeue();
    ASSERT_TRUE(n != nullptr);
    EXPECT_EQ(2, *n);
    EXPECT_EQ(1u, q2_.Size());
    delete n;
}

// Tests the Queue::Map() function.
TEST_F(QueueTest, Map) {
    MapTester(&q0_);
    MapTester(&q1_);
    MapTester(&q2_);
}

}  // namespace