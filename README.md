素朴な自作言語のコンパイラをCに移植した  
https://memo88.hatenablog.com/entry/2020/09/06/043607

```
gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) 
```

```sh
  $ LANG=C wc -l mrcl_*.c lib/{utils,types}.{c,h}
  571 mrcl_codegen.c
  190 mrcl_lexer.c
  628 mrcl_parser.c
  113 lib/utils.c
   17 lib/utils.h
  322 lib/types.c
   89 lib/types.h
 1930 total

  $ cat mrcl_*.c lib/{utils,types}.{c,h} | grep -v '^ *//' | wc -l
1911

  $ LANG=C wc -l lib/json.*
 141 lib/json.c
   4 lib/json.h
 145 total
```
