set nocompatible              " be iMproved, required
filetype off                  " required
call plug#begin('~/.vim/plugged')

Plug 'morhetz/gruvbox'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'jiangmiao/auto-pairs'
Plug 'itchyny/lightline.vim'
Plug 'easymotion/vim-easymotion'
call plug#end()
set nu
syntax on
"colorscheme desert  
let g:gruvbox_italic =1
colorscheme gruvbox 
set termguicolors
set nobackup
set noswapfile

func SkipPair()  
    if getline('.')[col('.') - 1] == ')' || getline('.')[col('.') - 1] == ']' || getline('.')[col('.') - 1] == '"' || getline('.')[col('.') - 1] == "'" || getline('.')[col('.') - 1] == '}'  
        return "\<ESC>la"  
    else  
        return "\t"  
    endif  
endfunc  

inoremap <TAB> <c-r>=SkipPair()<CR>
set noshowmode
set mouse=a
set mouse=v
set selection=exclusive
set selectmode=mouse,key
set ruler
set showmatch
set hlsearch
set autochdir
set cindent
set history=100
set autoread
set ws
set showcmd
"set cmdheight=l
set wildmenu
set wildmode=longest:list:full
set undofile
set undodir=~/.vim/.undo//
set smartcase
set ignorecase
set incsearch
set sidescrolloff=15
"----------------
set laststatus=2
set scrolloff=20
set softtabstop=4
set expandtab
set tabstop=4
set autoindent
filetype indent on
set t_Co=256
set shiftwidth=4
"--------------------
"sell bell-style off
set clipboard+=unnamed

set backspace=2
set report=0
":finish

inoremap kj <ESC>
"set fileencodings=gbk,utf-8,ucs-bom,gb18030,gb2312,cp936
 "  set termencoding=utf-8
set fenc=utf-8
set fencs=utf-8,usc-bom,euc-jp,gb18030,gbk,gb2312,cp936et encoding=utf-8
let mapleader = " "

set cursorline
"highlight CursorLin guibg=237
func setHead()
if &filetype == 'cpp'
call append(0, "#include<iostream>")
call append(1, "using namespace std;")
endif
endfunc
