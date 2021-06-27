# microBash

Simple shell implementation, that supports:
- search and launch the right executable
- **echo** with option ’-n’
- **cd** with only a relative or absolute path
- **pwd** without any options
- **export** without any options
- **unset** without any options
- **env** without any options and any arguments
- **exit** without any options
- Command separates with: **;**
- **'** and **"** (except for multiline commands)
- Redirections: **<> ">>"**
- Pipes: **|**
- Environmental variables: **$**
- **$?**
- Signals: **ctrl-C, ctrl-D, ctrl-\\**


## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
pip install foobar
```

## Usage

```python
import foobar

foobar.pluralize('word') # returns 'words'
foobar.pluralize('goose') # returns 'geese'
foobar.singularize('phenomena') # returns 'phenomenon'
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
