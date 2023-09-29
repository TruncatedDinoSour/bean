" Vim syntax file
" Language:     Beanconf
" Maintainer:   Ari Archer <ari.web.xyz@gmail.com>

" Usage Instructions
" Put this file in ~/.vim/syntax/beanconf.vim and
" then put beanconf.ftp.vim to ~/.vim/ftdetect/beanconf.ftp.vim

scriptencoding utf-8

if exists("b:current_syntax")
    finish
endif


" TODOs
syntax keyword bcTodo    TODO XXX FIXME NOTE


" Language keywords
syntax keyword bcKeyword can


" Numbers
syntax match bcNumber /\d*/
" ViM seems to hate '/-?\d*/'
syntax match bcNumber /-\d*/


" Comments
syntax region bcCommentLine start="# " end="$"    contains=bcTodo

" Booleans
syntax keyword bcBoolean true false yes no

" Set highlights
highlight default link bcTodo        Todo
highlight default link bcKeyword     Keyword
highlight default link bcCommentLine Comment
highlight default link bcNumber      Number
highlight default link bcBoolean     Boolean


" Set syntax
let b:current_syntax = "beanconf"
