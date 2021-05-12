CHECKER_DIR=./checker_dir
CHECKER=${CHECKER_DIR}/checker
PUSH_SWAP_DIR=./push_swap_dir
PUSH_SWAP=${PUSH_SWAP_DIR}/push_swap
MAKE=make -C
MAKE_F=make fclean -C
MAKE_C=make clean -C
MOVE=mv ${CHECKER} ${PUSH_SWAP} .
RM=rm -rf
COPY_CHECKER = cp ${CHECKER} .
COPY_PUSH_SWAP = cp ${PUSH_SWAP} .

all:
	${MAKE} ${CHECKER_DIR}
	${MAKE} ${PUSH_SWAP_DIR}
	${COPY_CHECKER}
	${COPY_PUSH_SWAP}

clean:
	${MAKE_C} ${CHECKER_DIR}
	${MAKE_C} ${PUSH_SWAP_DIR}

fclean:
	${MAKE_F} ${CHECKER_DIR}
	${MAKE_F} ${PUSH_SWAP_DIR}
	${RM} push_swap
	${RM} checker

re: fclean all

.PHONY: all clean fclean re