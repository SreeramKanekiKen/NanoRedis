#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

const size_t k_max_msg = 32 << 20;

static void die(const char *msg) {
    perror(msg);
    exit(1);
}

struct sockaddr_in {
    uint16_t sin_family;
    uint16_t sin_port;
    struct in_addr sin_addr;
};

struct in_addr {
    uint32_t s_addr;
};

struct sockaddr_in6 {
    uint16_t sin6_family;
    uint16_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
};

struct in6_addr {
    uint8_t sin6_addr[16];
};

static int32_t query(int fd, const char *text) {
    uint32_t len = uint32_t(strlen(text));
    if (len > k_max_msg) {
        return -1;
    }

    char wbuf[4 + k_max_msg] = {};
    memcpy(wbuf, &len, 4);
    memcpy(&wbuf[4], text, len);

    if (int32_t err = write_full(fd, wbuf, 4 + len)) {
        return err;
    }

    char rbuf[4 + k_max_msg];
    errno = 0;
    int32_t err = read_full(fd, rbuf, 4);

    if (err) {
        msg(errno == 0 ? "EOF" : "read() failed");
        return err;
    }

    memcpy(&len, rbuf, 4);
    if (len > k_max_msg) {
        msg("message too long");
        return -1;
    }

    err = read_full(fd, &rbuf[4], len);

    if (err) {
        msg("read() failed");
        return err;
    }

    printf("server says:%.*s\n", len, &rbuf[4]);
    return 0;
}

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0) {
        die("socket() failed");
    }

    struct sockaddr_in addr = {};

    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = ntohl(INADDR_LOOPBACK);

    int rv = connect(fd, (const struct sockaddr *)&addr, sizeof(addr));

    if (rv) {
        die("connect() failed");
    }

    int32_t err = query(fd, "hello1");
    if (err) {
        goto L_DONE;
    }

    err = query(fd, "hello2");
    if (err) {
        goto L_DONE;
    }

    L_DONE:
        close(fd);
        return 0;

    char msg[] = "hello";
    write(fd, msg, strlen(msg));

    char rbuf[64] = {};
    ssize_t n = read(fd, rbuf, sizeof(rbuf) - 1);

    if (n < 0) {
        die("read() failed");
    }

    cout<<"server says: "<<rbuf<<endl;
    
    close(fd);
}