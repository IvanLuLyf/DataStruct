//
// Created by IvanLu on 2017/10/21.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <sstream>

using namespace std;

#include "SeqStack.h"

class Calculator {
private:

    SeqStack<double> s;

    bool isDigit(char c) {  //判断是否是数字或小数点
        return c == '.' || (c >= '0' && c <= '9');
    }

    bool isAlphabeta(char c) {  //判断是不是字母
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    int isp(char c) {   //栈内优先数
        switch (c) {
            case '#':
                return 0;
            case '(':
                return 1;
            case '*':
            case '/':
            case '%':
                return 5;
            case '+':
            case '-':
                return 3;
            case ')':
                return 6;
            default:
                return -1;
        }
    }

    int icp(char c) {   //栈外优先数
        switch (c) {
            case '#':
                return 0;
            case '(':
                return 6;
            case '*':
            case '/':
            case '%':
                return 4;
            case '+':
            case '-':
                return 2;
            case ')':
                return 1;
            default:
                return -1;
        }
    }

    bool Pop(double &l, double &r) {    //弹出俩操作数
        if (s.isEmpty()) {
            cerr << "Right Operand Empty" << endl;
            return false;
        }
        s.Pop(r);
        if (s.isEmpty()) {
            cerr << "Left Operand Empty" << endl;
        }
        s.Pop(l);
        return true;
    }

    void doOperator(char op) {  //取俩操作数并计算
        double l, r, v;
        if (Pop(l, r)) {
            switch (op) {
                case '+':
                    v = l + r;
                    s.Push(v);
                    break;
                case '-':
                    v = l - r;
                    s.Push(v);
                    break;
                case '*':
                    v = l * r;
                    s.Push(v);
                    break;
                case '/':
                    if (r == 0.0) {
                        cerr << "Divide By Zero" << endl;
                        Clear();
                    }
                    v = l / r;
                    s.Push(v);
                    break;
            }
        } else {
            Clear();
        }
    }

    void Push(double val) { //操作数入栈
        s.Push(val);
    }

public:
    void Clear() {  //清空计数栈
        s.Clear();
    }

    double Eval(string expression, bool isPostfix = false) {
        stringstream ss;    //字符串流
        char ch;
        double Operand;
        if (isPostfix == false) {   //如果不是后缀表达式，先转成后缀表达式
            expression = toPostfix(expression) + '#';
        }
        if (expression[expression.length() - 1] != '#') {   //末尾没有终结符加一个终结符
            expression += '#';
        }
        ss << expression;
        while (ss >> ch, ch != '#') {   //循环输入判断
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                    doOperator(ch); //若为操作符则计算
                    break;
                default:
                    if (isDigit(ch)) {  //若为数字则将操作数压栈
                        ss.putback(ch);
                        ss >> Operand;
                        Push(Operand);
                    } else {    //若有其他字符则无法计算返回0
                        return 0;
                    }
                    break;
            }
        }
        s.getTop(Operand);
        return Operand;
    }

    //中缀表达式转后缀表达式
    string toPostfix(string expression) {
        SeqStack<char> stack;   //栈
        string result = "";
        char ch, tmp, op;
        int i = 0;
        stack.Push('#'); //栈底放入终结符
        ch = expression[i++];   //获取字符串中的内容
        while (!stack.isEmpty() && ch != '#') { //循环处理
            if (isDigit(ch) || isAlphabeta(ch)) {   //是数字或者字母
                result += ch;   //添加到结果字符串后
                ch = expression[i++];//获取字符串中的内容
            } else {
                if (result[result.length() - 1] != ' ') //分割元素，美化字符串
                    result += ' ';
                stack.getTop(tmp);  //获取栈顶操作符
                if (isp(tmp) < icp(ch)) {   //当前操作符优先级比栈顶操作符高
                    stack.Push(ch); //入栈
                    ch = expression[i++];//获取字符串中的内容
                } else if (isp(tmp) > icp(ch)) {//当前操作符优先级比栈顶操作符低
                    stack.Pop(op);  //出栈
                    if (op != '#')
                        result += op;//除终结符#外，其余操作符添加到结果字符串后
                } else {//当前操作符优先级比栈顶操作符相同
                    stack.Pop(op);  //出栈
                    if (op == '(') { //如果是左括号则继续读取
                        ch = expression[i++];//获取字符串中的内容
                    }
                }
            }
        }
        return result;
    }
};

#endif //CALCULATOR_H
