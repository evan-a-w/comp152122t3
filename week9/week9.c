#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
#include <sys/stat.h>

// stat(const char *path, struct stat *buf);

void fn(void) {
    struct stat st;
    if (stat("filename.txt", &st) != 0) {
        perror("filename.txt");
        exit(1);
    }
}

struct other_stat {
    ino_t st_ino;         /* inode number */
    mode_t st_mode;       /* protection - unsigned 32 bit integer */
    // rwx is encoded as three bits 111 (three octal digits for all permissions)
    // 777             x        
    // drwxrwxrwx      111 111 111
    // 0  1  2        876 543 210
    // st.st_mode & 0b10 ==> if its publically writable
    // S_IS_OWRIT(st.st_mode) (something like this - can't remember)
    // S_ISDIR(st.st_mode) ==> 0 if not, nonzero if so
    // change the mode of a file with chmod(const char *path, mode_t mode);
    uid_t st_uid;         /* user ID of owner */
    gid_t st_gid;         /* group ID of owner */
    off_t st_size;        /* total size, in bytes */
    // gives the size of the file
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t st_blocks;   /* number of 512B blocks allocated */
    time_t _st_atime;      /* time of last access */
    time_t _st_mtime;      /* time of last modification */
    time_t _st_ctime;      /* time of last status change */
};

// processes
