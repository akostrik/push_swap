# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2023/04/14 17:55:21 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

NAME      = push_swap
SRCS      = main.c put_args.c sort.c utils1.c utils2.c sort12345.c operations.c
OBJS      = ${SRCS:.c=.o}
HDRS      = push_swap.h
CFLAGS    = -Wall -Wextra -Werror
LIBFT     = libft
LIBFT_A   = libft/libft.a
CC        = cc

ARGS0     = 
ARGS1     = "   -2147483648  "
ARGS2     = 1 2
ARGS3     = "3 -2147483648 1"
ARGS4     = 1 3 4 2
ARGS5     = "  5 3  -2147483648  -4 d"
ARGS6     = 4 -5 -2147483648 1 -6 2147483647
ARGS7     = 1 4 6 +3 2 5 7
ARGS8     = -2147483648 -2147483647 -2 -1 0 1 2 +2147483647
ARGS9     = 1 4 1 3 9 2 8 5 7
ARGS10    = 1 2 3 4 5 6 7 8 9 10
ARGS11    = 1 11 4 2147483648 3 10 9 2 8 5 7
ARGS12    = 1 11 4 6 3 10 9 2 8 5 12 7
ARGS13    = 13 1 11 4 6 3 10 9 2 8 5 12 7
ARGS14    = 13 1 14 11 4 6 3 10 9 2 8 5 12 7
ARGS15    = 1 +2147483647 15 8 6 3 2 5 14 13 10 11 9 7 12
ARGS16    = 1 4 15 8 16 6 3 2 5 14 13 10 11 9 7 12
ARGS17    = "1 4 15 8 16 6 3 2 5 14 17 13 10 11 9 7 12"
ARGS18    = 1 4 15 8 16 6 3 2 5 18 14 17 13 10 11 9 7 12
ARGS31    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 22 31 15 16 20
ARGS32    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 32 22 31 15 16 20
ARGS33    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 33 32 22 31 15 16 20
ARGS48    = "42 43 19 38 1 37 2 25 26 3 18 34 35 36 24 39 4 40 5 6 7 21 8 44 23 45 17 27 41 9 10 46 11 47 28 30 48 12 13 29 14 33 32 22 31 15 16 20"
ARGS64    = 53 19 49 50 51 52 1 2 25 48 26 3 18 24 4 46 47 5 6 56 57 7 21 8 23 17 42 43 27 44 41 9 10 11 45 28 30 12 54 63 64 55 38 13 62 39 29 61 40 37 14 32 22 31 36 58 59 60 35 15 34 16 33 20
ARGS99    = 74 99 89 90 91 73 53 19 49 50 51 52 1 2 25 69 70 85 86 87 88 71 72 48 26 3 83 96 97 84 68 18 24 4 46 47 5 81 82 6 56 57 7 21 8 79 80 23 17 42 43 65 66 67 27 44 41 9 10 92 93 98 94 95 75 76 11 45 28 30 12 54 63 64 55 38 13 62 39 29 61 40 37 14 77 78 32 22 31 36 58 59 60 35 15 34 16 33 20
ARGS100   = 744661596 118308564 544013175 588278510 593313265 489472533 382619057 480982966 175072894 307297575 22908540 112312714 848098074 635617601 299333925 463669358 502027378 31588697 281612311 608350172 966188527 414489807 753110453 66408282 198145040 516691066 145368398 192270514 997024814 5385558 979741145 386207770 63816200 951918048 626043011 489486000 200935281 587743744 293845862 321211702 672257650 152236610 985561255 366070041 679233890 23085274 605817920 800119064 96796302 329949856 458834340 494725973 383221327 118071635 985489182 633042121 482426998 24577476 922564633 1862153 895388415 917538497 373238565 964757847 421089205 435200933 617572572 298668405 987789405 775802301 427817889 732163163 71177722 658961518 659097121 729257239 872509009 886879263 916994201 817280739 886904397 406533341 260668128 859946012 877010555 154923219 822526660 23186461 410574662 921836258 572530761 514433246 158847650 648610514 57466620 596116230 456901229 471938126 990905126 446591589
ARGS101   = 74 99 101 89 90 91 73 53 19 49 50 51 52 1 2 25 69 70 85 86 87 88 71 72 48 26 3 83 96 97 100 84 68 18 24 4 46 47 5 81 82 6 56 57 7 21 8 79 80 23 17 42 43 65 66 67 27 44 41 9 10 92 93 98 94 95 75 76 11 45 28 30 12 54 63 64 55 38 13 62 39 29 61 40 37 14 77 78 32 22 31 36 58 59 60 35 15 34 16 33 20
ARGS500   = 691200718 710407604 86647449 325068070 726413551 309746213 123625344 599498027 493457922 708473220 262967013 847242688 160937239 407514715 581006280 299068298 321042888 666088862 552548896 822557729 512932560 521377255 878279244 203568758 578184548 384920562 883024712 42939120 21262490 536217560 896192921 965372481 854233610 398587296 561771571 168479757 597227601 404946058 795274712 746826077 946872615 485849440 845357265 768826073 29270348 140422908 810303416 810893626 203894602 681133832 732634435 19993023 148182154 753645639 923802905 703619826 526843461 321913921 232248587 470734985 689879821 549952461 897142261 918504991 109642145 172000124 53432158 196805171 8731942 119195120 68039700 440882305 730127876 459990221 740220351 373794006 993479810 300768619 605397336 219164434 840182416 308843790 771953919 566016112 910842590 584658663 332663635 617886209 741107640 488119827 462538373 875274636 873990854 753688470 351076443 990266600 741438892 958217211 917605900 395605067 502279726 697050886 683966491 662428412 145995752 330165105 418549090 405940335 819484599 450184438 766104731 914806444 335285297 244535735 76168872 804311051 173364798 103743245 746394359 982175250 692543211 526309712 489581057 467798873 777600502 195316820 624902355 289508263 258603540 359863486 731079104 353257592 291888057 339432127 914046936 838633528 386161746 142796602 743870375 720766121 226502573 158764743 105317002 598758813 408651736 418427504 170773378 12675574 489774143 38762183 543289200 474041418 40165989 886481091 253789029 566041646 461656772 339565458 356221356 512401510 838016722 863527009 818287665 155244229 666470651 259015997 615410336 425979236 222438136 198795579 718881770 593165100 139072756 253371492 226692427 76651000 974543006 54680283 996759289 587321764 483080857 67576035 784945104 370402266 62607902 724345011 610076443 420512329 618994447 700771716 620525605 947536724 479323438 519394926 287637773 4537495 267154332 108839910 188710740 594850601 64206518 801237159 27360620 331793311 86219327 860875691 44629398 204107359 844325285 241534361 122750035 875344837 841296919 544129620 744874709 763014287 34311266 441719816 742835555 428555860 123387052 726457417 79055990 261652049 861667177 701359527 527308325 353442981 400968290 820793227 844001927 270214695 594855174 370118117 668447577 409358649 241590080 846287114 755835029 713563212 923150637 860593094 233204594 112043492 348896493 174310734 222943891 811402621 639917715 653725820 978785450 488555940 355323907 681531666 797170246 977992199 395276256 582719609 13772976 219446115 10831405 128684604 85479222 508634093 945388440 580042160 611063038 81131516 537084896 265600084 899960137 897586908 673130034 107182883 662433189 186293389 116343150 889469761 634497656 362841217 839961104 69209692 160162572 596565982 333730679 850142095 163216815 730206873 638471798 983869390 285693530 610523158 561284862 665325257 126049782 533081633 642750055 103223184 404109129 450042216 512605101 311302133 798923699 726452082 170666443 431568604 996017820 648671000 526422689 999755769 193534059 915351064 708326052 504517689 323217889 226120170 748183581 586203326 776187405 530146866 446677219 80439636 698429883 10153962 456322768 721021956 468869830 463064488 11771590 448113239 753972937 416602658 127984118 415126555 435476127 626502347 590671975 41705885 451731891 335663615 959945846 381186933 123284132 652060369 508167363 199701315 471612791 798314575 566254076 721408053 449696122 303697281 902261350 54298882 484339487 921756364 2667686 357687162 60351400 298499921 961992187 494801165 621586891 712468313 846876411 871791590 367420417 16914128 280190545 270543595 935093082 744507206 139807528 551625285 151460750 89167738 825649543 940742754 125611629 328085395 97878370 413095192 806114409 623946706 220081414 416637325 363121071 979215999 264874034 580358515 225774889 652262314 342165429 965968287 422603100 125024115 950805766 638487909 828348027 669490592 593675186 220974624 394329358 939587668 577470883 399753055 219811632 844377122 137497656 932089327 359799031 350273827 354396728 394205925 608789961 236990676 66593453 118653188 262067724 883994628 544796045 702229961 781168053 478568447 844936943 303042264 886841350 388280584 479129131 462654707 450445410 534831084 715989227 91389081 296518680 713019862 509594262 110490963 832785301 43000670 670804941 533070864 979475473 584785016 537458503 259841256 419671945 216192302 380700135 682169924 377872215 871736146 4143937 947065758 414965055 804704111 991885805 634876469 746530278 985528021 812745754 968308355 889011491 726920961 459485049 706365969 177887760 390627475 414808444 225195831 794014294 265571556 536239542 421629407 974304632 586038655 341776381 911778383 214109959 251084488 539990837 328447334 111651695 993791254 127143420 893543290 316702650 426107656 107306172 544922677 695807197 169782592 131908406 784401774 219774249 99424027 703368192 232642973 967127529 356595626
ARGS501   = -2147483648 2147483647 501 19 61 62 63 64 81 82 235 236 237 238 239 240 341 342 343 344 345 346 347 348 349 350 330 312 351 352 353 354 355 356 357 358 359 360 313 329 314 322 331 315 316 320 333 334 335 336 337 338 339 340 363 364 381 174 175 176 177 178 179 180 126 103 118 124 104 105 106 107 121 108 123 117 127 109 110 111 128 141 142 143 144 145 146 147 148 149 150 130 112 151 152 153 154 155 156 382 119 161 162 163 164 181 182 183 184 185 186 187 188 189 190 165 166 167 168 169 170 101 102 191 192 193 194 195 196 197 198 199 200 125 383 219 261 206 476 477 478 479 480 426 403 418 424 404 405 406 407 421 408 423 417 427 409 410 411 428 441 442 443 444 445 446 447 448 449 450 430 412 451 452 453 454 455 456 457 458 459 207 221 208 223 217 227 209 210 211 228 241 242 243 244 245 246 247 248 249 250 230 212 251 252 253 254 255 256 257 258 259 260 213 384 385 386 387 388 389 390 365 366 367 368 369 370 301 302 391 392 393 394 395 396 397 398 399 400 325 83 84 85 86 87 88 89 90 262 263 264 281 282 283 284 285 286 319 361 362 311 328 229 214 222 231 215 216 220 233 234 371 372 373 374 375 376 377 378 379 380 326 303 318 324 304 305 306 307 321 308 323 317 327 309 310 287 288 289 290 265 266 267 268 269 270 201 202 291 292 293 294 295 296 297 298 299 300 225 271 272 273 274 275 276 277 278 279 280 226 203 218 224 204 205 65 66 67 68 69 70 1 2 91 92 93 94 419 461 462 463 464 481 482 483 484 485 486 487 488 489 490 465 466 467 468 469 470 401 402 491 492 493 494 495 496 95 96 97 98 99 100 25 71 72 73 74 75 76 77 78 79 80 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 41 42 43 44 45 46 47 48 49 50 30 12 51 52 53 54 55 56 57 58 59 60 13 29 14 22 31 15 16 20 33 34 35 36 37 38 39 40 171 172 173 157 158 159 160 113 129 114 122 131 115 116 120 133 134 135 136 137 138 139 140 497 498 499 500 425 471 472 473 474 475 460 413 429 414 422 431 415 416 420 433 434 435 436 437 438 439 440
ARGS_1    = ""
ARGS_2    = "" ""
ARGS_3    = "\0"
ARGS_4    = --3
ARGS_5    = "03" "0"
ARGS_6    = "22147483648"
ARGS_7    = 2 5 6 + 3
ARGS_9    = 2\ 3\ 4\ 3
ARGS_10   = "2 5 6+3"
ARGS_11   = "4 2 3 1"
ARGS4_1   = "4 2 3 1"
ARGS4_2   = "2 3 4 1"
ARGS4_3   = "1 4 2 3"
ARGS4_4   = "2 4 3 1"
ARGS5_1   = "4 2 3 1 5"
ARGS5_2   = "4 2 5 3 1"
ARGS5_3   = "5 2 3 4 1"
ARGS5_4   = "3 4 5 1 2"
ARGS5_5   = "1 5 4 2 3"
ARGS5_6   = "2 4 5 1 3"
ARGS5_7   = "3 5 4 2 1"
#ARGS5_7   = "1 5 2 4 3"
# doesn't work: ARGS_8    = "8" 6\ "7"

all: ${NAME}
#	@./${NAME} ${ARGS4_1}
#	clear
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS1} | ./checker_linux ${ARGS1}
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS2} | ./checker_linux ${ARGS2}
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS3} | ./checker_linux ${ARGS3}
#	@./${NAME} ${ARGS4_1} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS4_1} | ./checker_linux ${ARGS4_1}
#	@./${NAME} ${ARGS4_2} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS4_2} | ./checker_linux ${ARGS4_2}
#	@./${NAME} ${ARGS4_3} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS4_3} | ./checker_linux ${ARGS4_3}
#	@./${NAME} ${ARGS4_4} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS4_4} | ./checker_linux ${ARGS4_4}
#	@./${NAME} ${ARGS5_1} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_1} | ./checker_linux ${ARGS5_1}
#	@./${NAME} ${ARGS5_2} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_2} | ./checker_linux ${ARGS5_2}
#	@./${NAME} ${ARGS5_3} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_3} | ./checker_linux ${ARGS5_3}
#	@./${NAME} ${ARGS5_4} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_4} | ./checker_linux ${ARGS5_4}
#	@./${NAME} ${ARGS5_5} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_5} | ./checker_linux ${ARGS5_5}
#	@./${NAME} ${ARGS5_6} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_6} | ./checker_linux ${ARGS5_6}
#	@./${NAME} ${ARGS5_7} | wc -l
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5_7} | ./checker_linux ${ARGS5_7}
#	@echo Empty output is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_11}
#	./${NAME} ${ARGS_11} | ./checker_linux ${ARGS_11}
#	./${NAME} ${ARGS17} | ./checker_linux ${ARGS17}
#	@echo Empty output is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_1}
#	@echo Empty output is expected:' 'sss
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS10}
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_2}
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_3}
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_4}
#	@echo -n
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_6}
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_7}
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_9}
#	@echo -n Error is expected:' '
#	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS_10}
#	@echo -n Error is expected:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS5}
#	@echo -n Error is expected:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS9}
#	@echo -n Error is expected:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS11}
#	@echo -n 0:'   '     ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS0} | wc -l
#	@echo -n 1:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS1} | wc -l
#	@echo -n 1:'   '  ; ./${NAME} ${ARGS1} | ./checker_linux ${ARGS1}
#	@echo -n 2:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS2} | wc -l
#	@echo -n 2:'   '  ; ./${NAME} ${ARGS2} | ./checker_linux ${ARGS2}
#	@echo -n 3:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS3} | wc -l
#	@echo -n 3:'   '  ; ./${NAME} ${ARGS3} | ./checker_linux ${ARGS3}
#	@echo -n 4:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS4} | wc -l
#	@echo -n 4:'   '  ; ./${NAME} ${ARGS4} | ./checker_linux ${ARGS4}
#	@echo -n 6:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS6} | wc -l
#	@echo -n 6:'   '  ; ./${NAME} ${ARGS6} | ./checker_linux ${ARGS6}
#	@echo -n 7:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS7} | wc -l
#	@echo -n 7:'   '  ; ./${NAME} ${ARGS7} | ./checker_linux ${ARGS7}
#	@echo -n 8:'   '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS8} | wc -l
#	@echo -n 8:'   '  ; ./${NAME} ${ARGS8} | ./checker_linux ${ARGS8}
#	@echo -n 12:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS12} | wc -l
#	@echo -n 12:'  '  ; ./${NAME} ${ARGS12} | ./checker_linux ${ARGS12}
#	@echo -n 13:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS13} | wc -l
#	@echo -n 13:'  '  ; ./${NAME} ${ARGS13} | ./checker_linux ${ARGS13}
#	@echo -n 14:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS14} | wc -l
#	@echo -n 14:'  '  ; ./${NAME} ${ARGS14} | ./checker_linux ${ARGS14}
#	@echo -n 15:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS15} | wc -l
#	@echo -n 15:'  '  ; ./${NAME} ${ARGS15} | ./checker_linux ${ARGS15}
#	@echo -n 16:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS16} | wc -l
#	@echo -n 16:'  '  ; ./${NAME} ${ARGS16} | ./checker_linux ${ARGS16}
#	@echo -n 17:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS17} | wc -l
#	@echo -n 17:'  '  ; ./${NAME} ${ARGS17} | ./checker_linux ${ARGS17}
#	@echo -n 18:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS18} | wc -l
#	@echo -n 18:'  '  ; ./${NAME} ${ARGS18} | ./checker_linux ${ARGS18}
#	@echo -n 31:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS31} | wc -l
#	@echo -n 31:'  '  ; ./${NAME} ${ARGS31} | ./checker_linux ${ARGS31}
#	@echo -n 32:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS32} | wc -l
#	@echo -n 32:'  '  ; ./${NAME} ${ARGS32} | ./checker_linux ${ARGS32}
#	@echo -n 33:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS33} | wc -l
#	@echo -n 33:'  '  ; ./${NAME} ${ARGS33} | ./checker_linux ${ARGS33}
#	@echo -n 48:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS48} | wc -l
#	@echo -n 48:'  '  ; ./${NAME} ${ARGS48} | ./checker_linux ${ARGS48}
#	@echo -n 64:'  '  ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS64} | wc -l
#	@echo -n 64:'  '  ; ./${NAME} ${ARGS64} | ./checker_linux ${ARGS64}
#	@ echo -n 99:'  ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS99} | wc -l
#	@ echo -n 99:'  ' ; ./${NAME} ${ARGS99}  | ./checker_linux ${ARGS99}
#	@ echo -n 100:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS100} | wc -l
#	@ echo -n 100:' ' ; ./${NAME} ${ARGS100} | ./checker_linux ${ARGS100}
#	@ echo -n 101:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS101} | wc -l
#	@ echo -n 101:' ' ; ./${NAME} ${ARGS101} | ./checker_linux ${ARGS101}
#	@ echo -n 500:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS500} | wc -l
#	@ echo -n 500:' ' ; ./${NAME} ${ARGS500} | ./checker_linux ${ARGS500} 
#	@ echo -n 501:' ' ; valgrind --leak-check=full --show-leak-kinds=all --quiet ./${NAME} ${ARGS501} | wc -l
#	@ echo -n 501:' ' ; ./${NAME} ${ARGS501} | ./checker_linux ${ARGS501} 

FORCE:

$(LIBFT_A): FORCE
	$(MAKE) -C $(dir ${LIBFT_A})

${NAME}: ${OBJS} ${HDRS} $(LIBFT_A)
	${CC} ${SRCS} -o ${NAME} $(LIBFT_A)

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C $(dir ${LIBFT_A})

fclean: clean
	rm -f ${NAME}
	$(MAKE) fclean -C $(dir ${LIBFT_A})

re: fclean all
	$(MAKE) re -C $(dir ${LIBFT_A})

.PHONY: all clean fclean re