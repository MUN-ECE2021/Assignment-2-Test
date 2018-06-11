#include <iostream>
#include <gtest/gtest.h>
#include "CircularQueue.h"
using namespace std;

//Command to Run Tests: c++ -std=c++11 test_gtest.cpp -lgtest -lgtest_main -lpthread


int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);

    //CircularQueue<int> qOne(3);

    return RUN_ALL_TESTS();
}

//Testing Constructor
TEST(QConTest, constructor){
    CircularQueue<int> qI(10);
    CircularQueue<double> qD(100);
    CircularQueue<string> qS(0);
}

//Copy COnstructor Test
TEST (QueCopyCons, CopyConstructor){
    //Testing for ints
    CircularQueue<int> qI(5);
    for (int i=0; i<5; i++){
        qI.enqueue((i+1)*10);
    }
    CircularQueue<int> qICopy(qI);
    for (int i =0; i<5; i++){
        ASSERT_EQ(qI.dequeue(), qICopy.dequeue());
        ASSERT_EQ(qI.depth(), qICopy.depth());
    }

    //Testing Strings
    CircularQueue<string> qS(7);
    qS.enqueue("mbTex");
    CircularQueue<string> qSCopy(qS);

    ASSERT_EQ(qS.dequeue(), qSCopy.dequeue());

}
//COPY ASSINGMENT OPERATOR
TEST (qCopy, ASSIGMENTS){
    CircularQueue<int> qI(10);
    CircularQueue<int> qI2(1);
    for(int i =0; i<10; i++){
        qI.enqueue(i+1);
        qI2.enqueue(i*10);
    }
    ASSERT_EQ(qI.peek(), 1);
    ASSERT_EQ(qI2.peek(), 0);

    qI2 = qI;
    ASSERT_TRUE(qI.full());
    ASSERT_TRUE(qI2.full());
    for (int i =0; i<10; i++){
        ASSERT_EQ(qI.dequeue(),qI2.dequeue() );
    }
    ASSERT_EQ(qI.depth(), qI2.depth());

}
//Testing Move Constructor
TEST (queue_MC, MoveConstructor){
    CircularQueue<int> qI(4);
    qI.enqueue(4);
    qI.enqueue(5);
    qI.enqueue(8);
    qI.enqueue(7);
    qI.enqueue(100);

    ASSERT_EQ(qI.depth(), 4);

    CircularQueue<int> bullyQ(std::move(qI));
    ASSERT_EQ(qI.depth(), 0);
    ASSERT_TRUE(qI.empty());
    ASSERT_FALSE(qI.full());

    ASSERT_EQ(bullyQ.dequeue(), 4);
    ASSERT_EQ(bullyQ.dequeue(), 5);
    ASSERT_EQ(bullyQ.dequeue(), 8);
    ASSERT_EQ(bullyQ.dequeue(), 7);
    ASSERT_EQ(bullyQ.dequeue(), 0);
}

//TESTING MOVE ASSINGMENT;
TEST(q_MA, MoveAssignment){
    CircularQueue<int> qI(7);
    CircularQueue<int> qOther(9);

    for (int i = 100; i >10; i--){
        qI.enqueue(i);
        qOther.enqueue(i%9);
    }
    ASSERT_EQ(qI.depth(), 7);
    ASSERT_EQ(qOther.depth(), 9);

    qOther = std::move(qI);
    ASSERT_EQ(qI.depth(), 0);
    ASSERT_EQ(qOther.depth(), 7);

    for (int i =100; i>93;i--){
        //ASSERT_EQ(qOther.dequeue(), i);
    }

}


//Testing empty que:
TEST(EmptyQueue, empty_and_Full) {

    //testing Int
    CircularQueue<int> qI (5);
    ASSERT_EQ(qI.empty(), true);
    ASSERT_EQ(qI.full(), false);

    //testing Strings
    CircularQueue<std::string> qString(5);
    ASSERT_EQ(qString.empty(), true);
    ASSERT_EQ(qString.full(), false);

    //testing Doubles
    CircularQueue<double> qD(0);
    ASSERT_FALSE(qD.enqueue(3.4));
    CircularQueue<double> qD2(1);
    ASSERT_TRUE(qD2.enqueue(25));
    ASSERT_FALSE(qD2.enqueue(26));
}

//Testing Enque Function
TEST(Enqueue, enQTest){
    CircularQueue<int> q (5);

    ASSERT_TRUE(q.enqueue(4));

    ASSERT_TRUE(q.enqueue(6));
    ASSERT_TRUE(q.enqueue(5));
    ASSERT_TRUE(q.enqueue(4));
    ASSERT_TRUE(q.enqueue(4));
    //insert limit reached
    ASSERT_TRUE(q.full());
    ASSERT_FALSE(q.enqueue(9));
    ASSERT_FALSE(q.enqueue(1000));

    //testing doubles
    CircularQueue<double> qD(10);
    for (int i =0; i<10; i++){
        //putting 10 items inside
        ASSERT_TRUE(qD.enqueue(i*3.14));
    }

    ASSERT_FALSE( qD.enqueue(3.14) );
    ASSERT_FALSE( qD.enqueue(3.14*3.14*4.14) );

    //testing Strings
    CircularQueue<string> qS(7);
    ASSERT_TRUE(qS.enqueue("Mohamed Biram"));
    ASSERT_TRUE(qS.enqueue("string2"));
    ASSERT_TRUE(qS.enqueue("adjacent"));
    ASSERT_TRUE(qS.enqueue("adjacent"));
    ASSERT_TRUE(qS.enqueue("adjacent"));
    ASSERT_TRUE(qS.enqueue("adjacent"));
    ASSERT_TRUE(qS.enqueue("adjacent"));
    ASSERT_FALSE(qS.enqueue("adjacent"));
}

//TEsting Dequeueing of
TEST(Dequeue, deqTest){
    //testing Ints
    CircularQueue<int> qI(5);
    ASSERT_EQ(qI.dequeue(), 0);

    for(int i =0; i< 5; i++){
        qI.enqueue(i+1);
    }
    ASSERT_EQ(qI.dequeue(),1);
    ASSERT_EQ(qI.dequeue(),2);
    ASSERT_EQ(qI.dequeue(),3);
    ASSERT_EQ(qI.dequeue(),4);
    ASSERT_EQ(qI.dequeue(),5);

    //Testing Doubles:
    CircularQueue<double> qD(10);
    for (int i =0; i<10; i++){
        qD.enqueue((i+1)*10);
    }
    ASSERT_EQ(qD.dequeue(), 10);
    ASSERT_EQ(qD.dequeue(), 20);
    ASSERT_EQ(qD.dequeue(), 30);
    ASSERT_EQ(qD.dequeue(), 40);
    ASSERT_EQ(qD.dequeue(), 50);
    ASSERT_EQ(qD.dequeue(), 60);
    ASSERT_EQ(qD.dequeue(), 70);
    ASSERT_EQ(qD.dequeue(), 80);
    ASSERT_TRUE(qD.enqueue(200));
    ASSERT_EQ(qD.dequeue(), 90);
    ASSERT_EQ(qD.dequeue(), 100);
    ASSERT_EQ(qD.dequeue(), 200);
    ASSERT_EQ(qD.dequeue(), 0);

}

//testing Peek function
TEST( qPEEK, PEEK ){
    CircularQueue<int> qI(5);
    for(int i =0; i<5; i++){
        qI.enqueue((i+1)*10);
    }
    int v = qI.peek();
    ASSERT_EQ( v, 10 );
    qI.dequeue();
    ASSERT_EQ(qI.peek(), 20);

    CircularQueue<string> qS(1);
    qS.enqueue("test");
    ASSERT_EQ(qS.peek(), "test");
}

TEST(full, testingFULL){
    CircularQueue<int> qI(3);

    ASSERT_TRUE(qI.empty());

    qI.enqueue(3);
    ASSERT_FALSE(qI.full());
    ASSERT_FALSE(qI.full());
    qI.enqueue(3);
    ASSERT_FALSE(qI.full());
    qI.enqueue(3);

    ASSERT_TRUE(qI.full());
    ASSERT_FALSE(qI.empty());

    //TODO: RUN TEST FOR AFTER DEQUE is working
    qI.dequeue();
    ASSERT_FALSE(qI.full());
    qI.dequeue();
    qI.dequeue();
    ASSERT_TRUE(qI.empty());
}

//Testing Depth
TEST (qDepth, depth){
    CircularQueue<double> qD(10);

    for(int i = 0; i<10; i++){
        qD.enqueue(i*3.14);
    }
    ASSERT_EQ(qD.depth(), 10);

    qD.enqueue(3.14);
    ASSERT_EQ(qD.depth(), 10);

    for (int i=1; i<11; i++){
        qD.dequeue();
        ASSERT_EQ(qD.depth(), 10-i);
    }

    for (int i =1; i<10; i++){
        qD.enqueue(i*10);
        ASSERT_EQ(qD.depth(), i);
    }

}
