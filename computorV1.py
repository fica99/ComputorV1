import argparse

def main():
	parser = argparse.ArgumentParser(description="Programm for the analysis of mathematical polynomials")
	parser.add_argument("-l", help="Display intermediate steps",action="store_true")
	parser.add_argument("-p", nargs=1, type=str, help="Mathematical polynomial", dest="polynomial", required=True)\

	args = parser.parse_args()
	

if __name__ == "__main__":
	main()
