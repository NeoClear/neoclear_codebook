#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

namespace io
{
    #define BLOCK (1 << 16)

    inline bool isterm(char c) {
        return c == ' ' ||
               c == '\n' ||
               c == '\t' ||
               c == '\r';
    }

    static char read_buf[BLOCK],
                *read_buf_s = read_buf,
                *read_buf_e = read_buf;

    static char write_buf[BLOCK];
    int write_buf_e = 0;

    inline char getc() {
        if (read_buf_s == read_buf_e) {
            read_buf_e = (read_buf_s = read_buf) +
                         fread(read_buf, 1, BLOCK, stdin);
            if (read_buf_s == read_buf_e)
                return EOF;
        }
        return *read_buf_s++;
    }

    inline int read_int() {
        int ans = 0;
        bool f = true;
        char ch = getc();
        while (!isdigit(ch)) {
            if (ch == '-')
                f = false;
            ch = getc();
        }
        while (isdigit(ch)) {
            ans = ans * 10 + ch - '0';
            ch = getc();
        }
        return f ? ans : -ans;
    }

    inline int64 read_int64() {
        int64 ans = 0;
        bool f = true;
        char ch = getc();
        while (!isdigit(ch)) {
            if (ch == '-')
                f = false;
            ch = getc();
        }
        while (isdigit(ch)) {
            ans = ans * 10 + ch - '0';
            ch = getc();
        }
        return f ? ans : -ans;
    }

    inline char read_char() {
        int ch = getc();
        while (isterm(ch))
            ch = getc();
        return ch;
    }

    inline void read_string(char *s) {
        int ch = getc();
        while (isterm(ch))
            ch = getc();
        while (!isterm(ch)) {
            (*s++) = ch;
            ch = getc();
        }
    }

    inline double read_double() {
        double ans = 0.0, w = 1.0;
        bool f = true;
        char ch = getc();
        while (!isdigit(ch)) {
            if (ch == '-')
                f = false;
            ch = getc();
        }
        while (isdigit(ch)) {
            ans = ans * 10 + ch - '0';
            ch = getc();
        }
        if (ch == '.') {
            ch = getc();
            while (isdigit(ch)) {
                w /= 10;
                ans += w * (ch - '0');
                ch = getc();
            }
        }
        return f ? ans : -ans;
    }

    int precision = 16;

    inline void setprecision(int x) {
        precision = x;
    }

    inline void flush() {
        fwrite(write_buf, 1, write_buf_e, stdout);
        write_buf_e = 0;
    }

    inline void putc(const char& c) {
        write_buf[write_buf_e++] = c;
        if (write_buf_e == BLOCK)
            flush();
    }

    inline void writes(const char c) {
        putc(c);
    }

    inline void writes(const char *s) {
        while (*s != '\0')
            putc(*s++);
    }

    inline void writes(int x) {
        bool f = x < 0;
        int p = 0;
        char s[32];
        while (x) {
            s[p++] = abs(x % 10) + '0';
            x /= 10;
        }
        if (f)
            putc('-');
        for (int i = p - 1; i >= 0; i--)
            putc(s[i]);
    }

    inline void writes(int64 x) {
        bool f = x < 0;
        int p = 0;
        char s[64];
        while (x) {
            s[p++] = abs(x % 10) + '0';
            x /= 10;
        }
        if (f)
            putc('-');
        for (int i = p - 1; i >= 0; i--)
            putc(s[i]);
    }

    inline void writes(double d) {
        ostringstream ost;
        ost.precision(precision);
        ost << d;
        writes(ost.str().c_str());
    }

    template <typename... T>
    inline void write(const T&... args) {
        (writes(args), ...);
    }
};

int main() {
    io::setprecision(32);
    char s[64];
    io::read_string(s);
    io::write("The time is: ", s);
    io::flush();
    return 0;
}