/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
*                           www.segger.com                           *
**********************************************************************

----------------------------------------------------------------------
Licensing information
For use with Embedded Studio only.
A valid license for Embedded Studio is required.
-------------------------- END-OF-HEADER -----------------------------
*/
# 1 "./fileops.c"
# 17 "./fileops.c"
#include "__SEGGER_RTL_Int.h"
#include "stdio.h"
#include "string.h"
#include "errno.h"
# 45 "./fileops.c"
static int __SEGGER_RTL_Read(FILE *stream, void *ptr, size_t n) {
  return __SEGGER_RTL_X_file_read(stream, ptr, n);
}
# 81 "./fileops.c"
int ungetc(int c, FILE *stream) {
  return __SEGGER_RTL_X_file_unget(stream, c);
}
# 112 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fgetc(FILE *stream) {
  unsigned char c;
  int stat;

  stat = __SEGGER_RTL_Read(stream, &c, 1);
  if (stat <= 0) {
    return EOF;
  } else {
    return c;
  }
}
# 141 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API getchar(void) {
  return fgetc(stdin);
}
# 165 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API getc(FILE *stream) {
  return fgetc(stream);
}
# 198 "./fileops.c"
char * __SEGGER_RTL_PUBLIC_API fgets(char *s, int n, FILE *stream) {
  char * pOut;
  int c;

  if (__SEGGER_RTL_X_file_stat(stream) < 0) {
    return NULL;
  }
  if (n == 0) {
    return NULL;
  }
  pOut = s;
  while (n > 1) {
    c = fgetc(stream);
    if (c < 0) {
      return NULL;
    }
    *pOut++ = c;
    --n;
    if (c == '\n') {
      break;
    }
  }
  *pOut = 0;
  return s;
}
# 251 "./fileops.c"
char * __SEGGER_RTL_PUBLIC_API gets(char *s) {
  char *a = s;

  for (;;) {
    int ch = getchar();
    if (ch == EOF) {
      if (s == a) {
        return NULL;
      }
      a = NULL;
      break;
    }
    if (ch == '\n') {
      break;
    }
    *s++ = (char)ch;
  }
  *s = 0;
  return a;
}
# 292 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API putchar(int c) {
  return fputc(c, stdout);
}
# 317 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API putc(int c, FILE *stream) {
  return fputc(c, stream);
}
# 343 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API puts(const char *s) {
  if (__SEGGER_RTL_X_file_write(stdout, s, (strlen)(s)) == EOF) {
    return EOF;
  } else {
    return putchar('\n');
  }
}
# 373 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fputs(const char *s, FILE *stream) {
  size_t len;

  len = (strlen)(s);
  if (fwrite(s, sizeof(char), len, stream) == len) {
    return 0;
  } else {
    return EOF;
  }
}
# 405 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fputc(int c, FILE * stream) {
  unsigned char uc;

  uc = (unsigned char)c;
  if (fwrite(&uc, sizeof(char), 1, stream) == 0) {
    return EOF;
  } else {
    return uc;
  }
}
# 429 "./fileops.c"
void __SEGGER_RTL_PUBLIC_API clearerr(FILE *stream) {
  __SEGGER_RTL_X_file_clrerr(stream);
}
# 451 "./fileops.c"
FILE * __SEGGER_RTL_PUBLIC_API fopen(const char *filename, const char *mode) {
  return __SEGGER_RTL_X_file_open(filename, mode);
}
# 472 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fclose(FILE *stream) {
  return __SEGGER_RTL_X_file_close(stream);
}
# 493 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API ferror(FILE *stream) {
  return __SEGGER_RTL_X_file_error(stream);
}
# 514 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API feof(FILE *stream) {
  return __SEGGER_RTL_X_file_eof(stream);
}
# 541 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fflush(FILE *stream) {
  return __SEGGER_RTL_X_file_flush(stream);
}
# 561 "./fileops.c"
void __SEGGER_RTL_PUBLIC_API rewind(FILE *stream) {
  fseek(stream, 0, SEEK_SET);
}
# 589 "./fileops.c"
size_t __SEGGER_RTL_PUBLIC_API fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  size_t n;



  if (__SEGGER_RTL_X_file_stat(stream) < 0) {
    return NULL;
  }



  n = size * nmemb;
  if (n == 0) {
    return 0;
  } else if (n < size) {
    n = (size_t)~0 / size;
  }

  return __SEGGER_RTL_X_file_read(stream, ptr, n) / size;
}
# 634 "./fileops.c"
size_t __SEGGER_RTL_PUBLIC_API fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  size_t n;

  if (__SEGGER_RTL_X_file_stat(stream) < 0) {
    return NULL;
  }
  n = size*nmemb;
  if (n < size) {
    return 0;
  } else {
    return __SEGGER_RTL_X_file_write(stream, ptr, n) / size;
  }
}
# 667 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fseek(FILE *stream, long offset, int whence) {
  return __SEGGER_RTL_X_file_seek(stream, offset, whence);
}
# 689 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fgetpos(FILE *stream, fpos_t *pos) {
  int stat;

  stat = __SEGGER_RTL_X_file_getpos(stream, pos);
  if (stat != 0) {
    errno = ESPIPE;
  }
  return stat;
}
# 721 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API fsetpos(FILE *stream, const fpos_t *pos) {
  int stat;

  stat = __SEGGER_RTL_X_file_seek(stream, *pos, SEEK_SET);
  if (stat != 0) {
    errno = ESPIPE;
  }
  return stat;
}
# 752 "./fileops.c"
long __SEGGER_RTL_PUBLIC_API ftell(FILE *stream) {
  long pos;

  if (__SEGGER_RTL_X_file_getpos(stream, &pos) < 0) {
    errno = ESPIPE;
    return -1L;
  } else {
    return pos;
  }
}
# 782 "./fileops.c"
FILE * __SEGGER_RTL_PUBLIC_API freopen(const char *filename, const char *mode, FILE *stream) {
  __SEGGER_RTL_USE_PARA(filename);
  __SEGGER_RTL_USE_PARA(mode);
  __SEGGER_RTL_USE_PARA(stream);

  return NULL;
}
# 809 "./fileops.c"
char * __SEGGER_RTL_PUBLIC_API tmpnam(char *s) {
  return __SEGGER_RTL_X_file_tmpnam(s, L_tmpnam);
}
# 827 "./fileops.c"
FILE * __SEGGER_RTL_PUBLIC_API tmpfile(void) {
  return __SEGGER_RTL_X_file_tmpfile();
}
# 849 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API rename(const char *oldname, const char *newname) {
  return __SEGGER_RTL_X_file_rename(oldname, newname);
}
# 870 "./fileops.c"
int __SEGGER_RTL_PUBLIC_API remove(const char *filename) {
  return __SEGGER_RTL_X_file_remove(filename);
}
# 887 "./fileops.c"
void __SEGGER_RTL_PUBLIC_API perror(const char *s) {
  if (s && s[0]) {
    fputs(s, stderr);
    fputs(": ", stderr);
  }
  fputs(strerror(errno), stderr);
  fputs("\n", stderr);
}

int __SEGGER_RTL_PUBLIC_API setvbuf(FILE *stream, char *buf, int mod, size_t size) {
  __SEGGER_RTL_USE_PARA(stream);
  __SEGGER_RTL_USE_PARA(buf);
  __SEGGER_RTL_USE_PARA(mod);
  __SEGGER_RTL_USE_PARA(size);

  return 0;
}

void __SEGGER_RTL_PUBLIC_API setbuf(FILE *stream, char *buf) {
  __SEGGER_RTL_USE_PARA(stream);
  __SEGGER_RTL_USE_PARA(buf);


}
