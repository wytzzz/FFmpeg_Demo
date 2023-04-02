#include <iostream>
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
}

int main() {
    std::cout << avformat_configuration();
    return 0;
}
