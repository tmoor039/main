#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int pfds[2];

    pipe(pfds);

    if (!fork()) {
        fprintf(stderr, "In the parent.\n");
        fprintf(stderr, "parent: close stdout.\n");
        close(1);      /* close stdout */
        fprintf(stderr, "parent: dup stdout.\n");
        dup(pfds[1]);  /* make stdout pfds[1] */
        fprintf(stderr, "parent: close other end.\n");
        close(pfds[0]); /* don't need this */
        fprintf(stderr, "parent: call exec on ls.\n");
        execlp("ls", "ls", NULL);
    } else {
        fprintf(stderr, "In the child.\n");
        fprintf(stderr, "child: close stdin.\n");
        close(0);       /* close stdin */
        fprintf(stderr, "child: dup stdin.\n");
        dup(pfds[0]);   /* make stdin pfds[0] */
        fprintf(stderr, "child: close other end.\n");
        close(pfds[1]);
        fprintf(stderr, "child: call exec on wc.\n");

        execlp("wc", "wc", "-l", NULL);

    }
    return 0;
}
