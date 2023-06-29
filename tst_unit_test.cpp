#include <QtTest>

// add necessary includes here

class unit_test : public QObject
{
    Q_OBJECT

public:
    unit_test();
    ~unit_test();

private slots:
    void test_case1();

};

unit_test::unit_test()
{

}

unit_test::~unit_test()
{

}

void unit_test::test_case1()
{

}

QTEST_APPLESS_MAIN(unit_test)

#include "tst_unit_test.moc"
