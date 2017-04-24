import difflib, argparse, subprocess, sys, os


def preprocess(compiler, file_contents):
    """ Get output from the preprocessing pass on a file.  """
    return subprocess.Popen(
            [compiler, '-E', '-'], 
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            stdin=subprocess.PIPE).communicate(input=file_contents)[0]


def preprocess_file(compiler, filename):
    """ Open a file and get the preprocessor output.  """
    with open(filename) as f:
        return preprocess(compiler, f.read())


def remove_empty_lines(text):
    """ Remove empty lines from text.  """
    return '\n'.join(filter(None, text.splitlines()))


def file_contents_from_branch(filename, branch):
    """ Get a copy of a file from another branch and return its contents.  """
    return subprocess.check_output(
            ['git', 'show', '%s:%s' % (branch, filename)])


def equal_to_file_on_branch(filename, branch, compiler):
    """
    Open a file on this branch and preprocess it.  Preprocess the same file
    from another branch, and return whether the two files have (for all intents
    and purposes) the same contents.
    """
    with open(filename) as f:
        def process(text):
            return remove_empty_lines(preprocess(compiler, text))
        return (process(f.read()) ==
                process(file_contents_from_branch(filename, branch)))


def process_single_file(filename, branch, compiler):
    """ Like equal_to_file_on_branch, but also checks the file extension.  """
    _, ext = os.path.splitext(filename)
    return ((ext == '.h' or ext == '.cpp') and 
            not equal_to_file_on_branch(filename, branch, compiler))


def main():
    """
    Open a file and compare its preprocessor output to the output from the same
    file on a different branch.  Return 0 if the outputs match, or 1 otherwise.
    """
    parser = argparse.ArgumentParser()
    parser.add_argument(
            '--branch', type=str, default='upstream/master',
            help='The branch to compare')
    parser.add_argument(
            '--compiler', type=str, default='gcc',
            help='The compiler to use')
    args = parser.parse_args()

    for root, dirs, files in os.walk('.'):
        for f in files:
            full_path = os.path.join(root, f)
            if process_single_file(full_path, args.branch, args.compiler):
                print(full_path)
                return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
