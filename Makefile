CHECKER=./checker
PUSH_SWAP=./push_swap
MAKE=make -C
MAKE_F=make fclean -C
MAKE_C=make clean -C

all:
	${MAKE} ${CHECKER}
	${MAKE} ${PUSH_SWAP}

clean:
	${MAKE_C} ${CHECKER}
	${MAKE_C} ${PUSH_SWAP}

fclean:
	${MAKE_F} ${CHECKER}
	${MAKE_F} ${PUSH_SWAP}

re: fclean all
