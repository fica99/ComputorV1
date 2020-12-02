#include "cmd_parser.h"

using namespace	std;

static void	ConfigureParser(cli::Parser& parser) {
	parser.set_optional<bool>("l", "long", false, "Display intermediate steps");
	parser.set_required<string>("p", "polynomial", "Mathematical polynomial", true);
	parser.run_and_exit_if_error ();
}

int					main(int argc, char **argv) {
	cli::Parser	parser(argc, argv);

	ConfigureParser(parser);
	cout << parser.get<string>("p") << parser.get<bool>("l") << endl;
	return (0);
}
