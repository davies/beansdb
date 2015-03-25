#include <stdio.h>
#include <stdlib.h>

#include "hstore.h"

bool copy_to(DataRecord *r, void *arg) {
    HStore *dst = arg;
    hs_set(dst, r->key, record_value(r), r->vsz, r->flag, r->version);
    return true;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: convert <src> <src_depth> <dst> <dst_depth>\n");
        exit(0);
    }
    const char *src = argv[1];
    int src_depth = atoi(argv[2]);
    const char *dst = argv[3];
    int dst_depth = atoi(argv[4]);

    HStore *hsrc = hs_open(src, src_depth, 0, 4);
    if (hsrc==NULL) {
        fprintf(stderr, "can not open %s\n", src);
        exit(1);
    }
    HStore *hdst = hs_open(dst, dst_depth, 0, 1);
    if (hdst==NULL) {
        fprintf(stderr, "can not open %s\n", dst);
        exit(1);
    }
    printf("copy %s to %s ...\n", src, dst);
    int copied = hs_visit(hsrc, copy_to, hdst);
    if (copied >= 0) {
        printf("copied %d items successfully\n", copied);
    } else {
        printf("failed after copied %d items\n", -copied);
    }
    hs_close(hdst);
    hs_close(hsrc);
}
