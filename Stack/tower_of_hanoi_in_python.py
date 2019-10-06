def tof(disks, source, middle, target):
    if disks == 1:
        print(f"Move disk 1 from tower {source} to tower {target}.")
        return

    tof(disks - 1, source, target, middle)
    print(f"Move disk {disks} from tower {source} to tower {target}.")
    tof(disks - 1, middle, source, target)


def main():
    disks = int(input("Enter number of disks: "))
    tof(disks, "A", "B", "C")


main()
