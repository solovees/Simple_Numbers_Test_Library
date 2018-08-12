#include <QtTest>
#include "../../Lab3_library/lab3_prost/lab3_prost.h"

class test_simple_numbers : public QObject
{
    Q_OBJECT

public:
    test_simple_numbers();
    ~test_simple_numbers();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_without_one();
    void test_border_NbOne_Zero();
    void test_border_NbOne_Con();
    void test_border_NbTwo_Zero();
    void test_border_NbTwo_Con();
    void test_NbOne_less_NbTwo();
    void test_NbOne_not_NbTwo();
    void test_All_SN();
    void test_upper_include();
    void test_lower_include();

};

test_simple_numbers::test_simple_numbers()
{

}

test_simple_numbers::~test_simple_numbers()
{

}

void test_simple_numbers::initTestCase()
{

}

void test_simple_numbers::cleanupTestCase()
{

}

void test_simple_numbers::test_without_one()
{
    QCOMPARE(TwoNumber::getList(1,2), std::vector<int>({2}));
}

void test_simple_numbers::test_border_NbOne_Zero()
{
    try{
        TwoNumber::getList(0,2);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("a must be positive"));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_border_NbOne_Con()
{
    try{
        TwoNumber::getList(-1,2);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("a must be positive"));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_border_NbTwo_Zero()
{
    try{
        TwoNumber::getList(1,0);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("b must be positive"));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_border_NbTwo_Con()
{
    try{
        TwoNumber::getList(2,-1);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("b must be positive"));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_NbOne_less_NbTwo()
{
    try{
        TwoNumber::getList(15,14);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("Число A больше B "));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_NbOne_not_NbTwo()
{
    try{
        TwoNumber::getList(14,14);
        QFAIL("Не возникло исключение");
    } catch(std::out_of_range const & e){
        QCOMPARE(QString(e.what()),QString("Число A больше B "));
    } catch(std::exception const & e){
        QFAIL("Возникло неверное исключение");
    }
}

void test_simple_numbers::test_All_SN()
{
    QBENCHMARK{
        TwoNumber::getList(10000,99999);
    }

}

void test_simple_numbers::test_upper_include()
{
    QCOMPARE(TwoNumber::getList(9,11), std::vector<int>({11}));
}

void test_simple_numbers::test_lower_include()
{
    QCOMPARE(TwoNumber::getList(11,12), std::vector<int>({11}));
}



QTEST_APPLESS_MAIN(test_simple_numbers)

#include "tst_test_simple_numbers.moc"
