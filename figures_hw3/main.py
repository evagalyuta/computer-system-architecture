import sys
import timeit

from entity.container import Container


# Error message.
def err_message1():
    print("incorrect command line!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n")


# Error message.
def err_message2():
    print("incorrect qualifier value!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n")


if __name__ == "__main__":
    if len(sys.argv) != 5:
        err_message1()
        str =""
        line = str.strip().split()
        print(type(line))
        sys.exit()
    print("Start")
    first = timeit.default_timer()

    container = Container()

    if sys.argv[1] == "-f":
        container.input(sys.argv[2])
    elif sys.argv[1] == "-n":
        size = int(sys.argv[2])
        if (size < 1) or (size > 30000):
            raise ValueError("Incorrect number of figures.")
        container.in_rnd(int(sys.argv[2]))
    else:
        err_message2()

    container.out(sys.argv[3])
    container.shaker_sort()
    container.out(sys.argv[4])
    print(timeit.default_timer() - first)
    print("Stop")
