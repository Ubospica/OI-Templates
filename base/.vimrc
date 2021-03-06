set nu
set mouse=a
set nocp
set shiftwidth=3 tabstop=4 softtabstop=4
set showmatch
set autoread
set confirm "confirm for saving changes
set cindent autoindent smartindent
set ignorecase
"set hlsearch
set ruler
set encoding=UTF-8

syntax on
map  <c-a> ggVG
imap <c-a> <esc><c-a>
map  <c-v> "+p
imap <c-v> <esc><c-v>i
vmap <c-c> "+y
vmap <c-x> "+d
imap <c-e> <esc><c-e>i<right>
imap <c-y> <esc><c-y>i<right>

map <F5> :w<cr>:sp ~/oi/gdb.in<cr><c-a><c-c>:q!<cr>:!g++ % -o exec -g3 -std=c++11 -Wall -Wextra && gdb exec <cr>
map <F9> :w<CR>:!g++ % -o exec -O2 -std=c++11 -Wall -Wextra && ./exec <CR>

inoremap ' ''<esc>i
inoremap " ""<esc>i
inoremap ( ()<esc>i
inoremap [ []<esc>i
inoremap { {}<esc>i
