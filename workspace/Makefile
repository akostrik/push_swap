# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2023/03/10 17:08:37 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	valgrind --leak-check=full --show-leak-kinds=all ./${NAME} ${ARGS}
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

NAME      = push_swap
SRCS      = main.c put_args.c sort.c sort_5_and_shorter.c operations.c\
            utils1.c utils2.c utils3.c
OBJS      = ${SRCS:.c=.o}
HDRS      = .
CFLAGS    = -Wall -Wextra -Werror
LIBFT_A   = libft/libft.a
CC        = cc
ARGS0     = 
ARGS1     = "  -2147483648 "
ARGS2     = 2 1
ARGS2_    = 1 2
ARGS3     = "3 -2147483648 1"
ARGS4     = 1 -3 4 2
ARGS5     = "  5 3  -2147483648  -4 +2"
ARGS5     = -3 5 3 -4 2
ARGS6     = 4 -5 3 1 -6 2
ARGS7     = 1 4 6 +3 2 5 7
ARGS8     = 1 4 6 3 +2 -8 5 7
ARGS9     = 1 4 6 3 9 -2147483648 8 5 7
ARGS9     = 1 4 6 3 9 2 8 5 7
ARGS15    = 1 +2147483647 15 8 6 3 2 5 14 13 10 11 9 7 12
ARGS16    = 1 4 15 8 16 6 3 2 5 14 13 10 11 9 7 12
ARGS17    = "1 4 15 8 16 6 3 2 5 14 17 13 10 11 9 7 12"
ARGS17_   = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
ARGS18    = 1 4 15 8 16 6 3 2 5 18 14 17 13 10 11 9 7 12
ARGS31    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 22 31 15 16 20
ARGS32    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 32 22 31 15 16 20
ARGS33    = 19 1 2 25 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 30 12 13 29 14 33 32 22 31 15 16 20
ARGS48    = "42 43 19 38 1 37 2 25 26 3 18 34 35 36 24 39 4 40 5 6 7 21 8 44 23 45 17 27 41 9 10 46 11 47 28 30 48 12 13 29 14 33 32 22 31 15 16 20"
ARGS64    = 53 19 49 50 51 52 1 2 25 48 26 3 18 24 4 46 47 5 6 56 57 7 21 8 23 17 42 43 27 44 41 9 10 11 45 28 30 12 54 63 64 55 38 13 62 39 29 61 40 37 14 32 22 31 36 58 59 60 35 15 34 16 33 20
ARGS100   = 74 99 89 90 91 73 53 19 49 50 51 52 1 2 25 69 70 85 86 87 88 71 72 48 26 3 83 96 97 100 84 68 18 24 4 46 47 5 81 82 6 56 57 7 21 8 79 80 23 17 42 43 65 66 67 27 44 41 9 10 92 93 98 94 95 75 76 11 45 28 30 12 54 63 64 55 38 13 62 39 29 61 40 37 14 77 78 32 22 31 36 58 59 60 35 15 34 16 33 20
ARGS500   = -2147483648 2147483647 19 61 62 63 64 81 82 235 236 237 238 239 240 341 342 343 344 345 346 347 348 349 350 330 312 351 352 353 354 355 356 357 358 359 360 313 329 314 322 331 315 316 320 333 334 335 336 337 338 339 340 363 364 381 174 175 176 177 178 179 180 126 103 118 124 104 105 106 107 121 108 123 117 127 109 110 111 128 141 142 143 144 145 146 147 148 149 150 130 112 151 152 153 154 155 156 382 119 161 162 163 164 181 182 183 184 185 186 187 188 189 190 165 166 167 168 169 170 101 102 191 192 193 194 195 196 197 198 199 200 125 383 219 261 206 476 477 478 479 480 426 403 418 424 404 405 406 407 421 408 423 417 427 409 410 411 428 441 442 443 444 445 446 447 448 449 450 430 412 451 452 453 454 455 456 457 458 459 207 221 208 223 217 227 209 210 211 228 241 242 243 244 245 246 247 248 249 250 230 212 251 252 253 254 255 256 257 258 259 260 213 384 385 386 387 388 389 390 365 366 367 368 369 370 301 302 391 392 393 394 395 396 397 398 399 400 325 83 84 85 86 87 88 89 90 262 263 264 281 282 283 284 285 286 319 361 362 311 328 229 214 222 231 215 216 220 233 234 371 372 373 374 375 376 377 378 379 380 326 303 318 324 304 305 306 307 321 308 323 317 327 309 310 287 288 289 290 265 266 267 268 269 270 201 202 291 292 293 294 295 296 297 298 299 300 225 271 272 273 274 275 276 277 278 279 280 226 203 218 224 204 205 65 66 67 68 69 70 1 2 91 92 93 94 419 461 462 463 464 481 482 483 484 485 486 487 488 489 490 465 466 467 468 469 470 401 402 491 492 493 494 495 496 95 96 97 98 99 100 25 71 72 73 74 75 76 77 78 79 80 26 3 18 24 4 5 6 7 21 8 23 17 27 9 10 11 28 41 42 43 44 45 46 47 48 49 50 30 12 51 52 53 54 55 56 57 58 59 60 13 29 14 22 31 15 16 20 33 34 35 36 37 38 39 40 171 172 173 157 158 159 160 113 129 114 122 131 115 116 120 133 134 135 136 137 138 139 140 497 498 499 500 425 471 472 473 474 475 460 413 429 414 422 431 415 416 420 433 434 435 436 437 438 439 440

all: ${NAME}
	clear
	./${NAME} ${ARGS6}

#	@echo -n *** 0 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./${NAME} ${ARGS0} | wc -l
#	@./${NAME} ${ARGS0} | ./checker_linux ${ARGS0}
#	@echo -n *** 1 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS1} | wc -l
#	@./${NAME} ${ARGS1}
#	@./${NAME} ${ARGS1} | ./checker_linux ${ARGS1}
#	@echo -n *** 2 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all ./${NAME} ${ARGS2} | wc -l
#	@./${NAME} ${ARGS2} | ./checker_linux ${ARGS2}
#	@echo -n 2 already in ordre ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all ./${NAME} ${ARGS2_} | wc -l
#	@./${NAME} ${ARGS2_} | ./checker_linux ${ARGS2_}
#	@echo -n *** 3 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS3} | wc -l
#	@./${NAME} ${ARGS3} | ./checker_linux ${ARGS3}
#	@echo -n *** 4 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS4} | wc -l
#	@./${NAME} ${ARGS4} | ./checker_linux ${ARGS4}
#	@echo -n *** 5 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS5} | wc -l
#	@./${NAME} ${ARGS5} | ./checker_linux ${ARGS5}
#	@echo -n *** 7 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS7} | wc -l
#	@./${NAME} ${ARGS7} | ./checker_linux ${ARGS7}
#	@echo -n *** 8 ' '
#	@./${NAME} ${ARGS8} | wc -l
#	@./${NAME} ${ARGS8} | ./checker_linux ${ARGS8}
#	@echo -n *** 9 ' '
#	@./${NAME} ${ARGS8} | wc -l
#	@./${NAME} ${ARGS8} | ./checker_linux ${ARGS8}
#	@echo -n *** 15 ' '
#	@./${NAME} ${ARGS15} | wc -l
#	@./${NAME} ${ARGS15} | ./checker_linux ${ARGS15}
#	@echo -n *** 16 ' '
#	@./${NAME} ${ARGS16} | wc -l
#	@./${NAME} ${ARGS16} | ./checker_linux ${ARGS16}
#	@echo -n *** 17 ' '
#	@./${NAME} ${ARGS17} | wc -l
#	@./${NAME} ${ARGS17} | ./checker_linux ${ARGS17}
#	@echo -n *** 17 already in ordre ' '
#	@./${NAME} ${ARGS17_} | wc -l
#	@./${NAME} ${ARGS17_} | ./checker_linux ${ARGS17_}
#	@echo -n *** 18 ' '
#	@./${NAME} ${ARGS18} | wc -l
#	@./${NAME} ${ARGS18} | ./checker_linux ${ARGS18}
#	@echo -n *** 31 ' '
#	@./${NAME} ${ARGS31} | wc -l
#	@./${NAME} ${ARGS31} | ./checker_linux ${ARGS31}
#	@echo -n *** 32 ' '
#	@./${NAME} ${ARGS32} | wc -l
#	@./${NAME} ${ARGS32} | ./checker_linux ${ARGS32}
#	@echo -n *** 33 ' '
#	@./${NAME} ${ARGS33} | wc -l
#	@./${NAME} ${ARGS33} | ./checker_linux ${ARGS33}
#	@echo -n *** 48 ' '
#	@./${NAME} ${ARGS48} | wc -l
#	@./${NAME} ${ARGS48} | ./checker_linux ${ARGS48}
#	@echo -n *** 64 ' '
#	@./${NAME} ${ARGS64} | wc -l
#	@./${NAME} ${ARGS64} | ./checker_linux ${ARGS64}
#	@echo -n *** 100 ' '
#	@./${NAME} ${ARGS100} | wc -l
#	@./${NAME} ${ARGS100} | ./checker_linux ${ARGS100}
#	@echo -n *** 500 ' '
#	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} ${ARGS500} | wc -l
#	@./${NAME} ${ARGS500} | ./checker_linux ${ARGS500}

${NAME}: ${OBJS} push_swap.h
	$(MAKE) -C $(dir ${LIBFT_A})
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

.PHONY: all clean fclean re