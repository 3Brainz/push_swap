CHECKER_DIR=./checker
CHECKER=${CHECKER_DIR}/checker
PUSH_SWAP_DIR=./push_swap
PUSH_SWAP=${PUSH_SWAP_DIR}/push_swap
MAKE=make -C
MAKE_F=make fclean -C
MAKE_C=make clean -C
MOVE=mv ${CHECKER} ${PUSH_SWAP} .
RM=rm -rf

all:
	${MAKE} ${CHECKER_DIR}
	${MAKE} ${PUSH_SWAP_DIR}

clean:
	${MAKE_C} ${CHECKER_DIR}
	${MAKE_C} ${PUSH_SWAP_DIR}

fclean:
	${MAKE_F} ${CHECKER_DIR}
	${MAKE_F} ${PUSH_SWAP_DIR}

re: fclean all
