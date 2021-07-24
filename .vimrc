"
"  dein.vim
"
set runtimepath+=~/.cache/dein/repos/github.com/Shougo/dein.vim
if dein#load_state('~/.cache/dein')
  call dein#begin('~/.cache/dein')
  let s:toml = '~/.cache/dein/dein.toml'
  call dein#load_toml(s:toml, {'lazy':0})

  call dein#add('scrooloose/nerdtree')
  call dein#end()
  call dein#save_state()
endif

filetype plugin indent on
syntax enable
" If you want to install not installed plugins on startup.
if dein#check_install()
  call dein#install()
endif

"setting
" フォント設定:
" set guifont=DejaVu\ Sans\ Mono\13 
set linespace=0
"文字コードをUFT-8に設定
inoremap <silent> jj <ESC>
inoremap <silent> jk <ESC>
"set fenc=utf-8
" vimの内部文字コード　（これを書くと、上記の優先度設定が無視されます）
":set encoding=utf-8

" ファイルのエンコーディング（改行コードの種類）
:set fileformat=unix
" バックアップファイルを作らない
set nobackup
" スワップファイルを作らない
set noswapfile
" 編集中のファイルが変更されたら自動で読み直す
set autoread
" バッファが編集中でもその他のファイルを開けるように
set hidden
" 入力中のコマンドをステータスに表示する
set showcmd
" 見た目系
" 行番号を表示
set number
" 改行時に入力された行の末尾に合わせて次の行のインデントを増減する
set smartindent
" シンタックスハイライト
syntax on
" 括弧入力時の対応する括弧を表示
set showmatch
" ステータスラインを常に表示
set laststatus=2
" コマンドラインの補完
set wildmode=list:longest
" シンタックスハイライトの有効化
syntax enable
" コメントの色を水色
hi Comment ctermfg=3
" 対応する括弧を強調表示
set showmatch

" Tab系
" 行頭以外のTab文字の表示幅（スペースいくつ分）
set tabstop=4
" 行頭でのTab文字の表示幅
set shiftwidth=0


" 検索系
" let g:auto_save = 1
if has('persistent_undo')
  set undodir=~/.vim/undo
  set undofile                                                                                                                                   
endif
set clipboard=unnamedplus
"WSL yank support
let s:clip = '/mnt/c/Windows/System32/clip.exe'
if executable(s:clip)
  augroup WSLYank
    autocmd!
    autocmd TextYankPost * if v:event.operator ==# 'y' | call system(s:clip, @0) | endif
  augroup END
endif

" Ctrl-nでNERDTreeを開く
map <C-n> :NERDTreeToggle<CR>
" 隠しファイルを表示する
let NERDTreeShowHidden = 1
" 検索結果をハイライト
set hlsearch
" 現在の行をハイライト
" set cursorline 
" カーソルの形状を挿入モード時に棒にする
if has('vim_starting')
	" 挿入モード時に非点滅の縦棒タイプのカーソル
	let &t_SI .= "\e[6 q"
	" ノーマルモード時に非点滅のブロックタイプのカーソル
	let &t_EI .= "\e[2 q"
	" 置換モード時に非点滅の下線タイプのカーソル
	" let &t_SR .= "\e[4 q"
endif
" ハイライトを無効にする
set hlsearch!
nnoremap <F3> :set hlsearch!<CR>
