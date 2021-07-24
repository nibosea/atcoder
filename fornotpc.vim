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

" ハイライトを無効にする
set hlsearch!
nnoremap <F3> :set hlsearch!<CR>
