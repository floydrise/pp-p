#ifndef B1_H
#define B1_H
#include <string>

namespace Drill {
    class B1 {
        // abstract class
    public:
        virtual void vf();

        virtual void pvf() =0;

        static void f();
    };

    class D1 : public B1 {
        // abstract class
    public:
        void vf() override;

        static void f();
    };

    class D2 : public D1 {
    public:
        void pvf() override;
    };

    class B2 {
    public:
        virtual void vpf() =0;
    };

    class D21 : public B2 {
    public:
        void vpf() override;

        D21(const std::string &inp): str(inp) {
        };

    private:
        std::string str;
    };

    class D22 : public B2 {
    public:
        void vpf() override;

        D22(const int inp) : num(inp) {
        };

    private:
        int num = 0;
    };

    inline void f(B2 &val) {
        val.vpf();
    };
}


#endif //B1_H
