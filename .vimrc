set relativenumber
set ruler
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set cursorline
set hlsearch
set nu

" color scheme
syntax on
syntax enable
set t_Co=256
colorscheme molokai

" cursor type
let &t_SI = "\e[6 q"
let &t_EI = "\e[2 q"

" Compile function
noremap <F5> :call CompileRunGcc()<CR>
function! CompileRunGcc()
  execute "w"
  "execute "!echo -e \"\n\n--------start--------\n\n\""
  if &filetype == 'cpp'
    execute "!g++ % && ./a.out"
  endif

  if &filetype == 'c'
    execute "!gcc % && ./a.out"
  endif
  "execute "!echo -e \"\n\n---------end---------\n\n\""
endfunction

" brackets match
hi MatchParen cterm=underline ctermbg=black ctermfg=white
"highlight MatchParen term=underline cterm=underline gui=underline
