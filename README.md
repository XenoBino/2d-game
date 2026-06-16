# 2d-game

A basic 2D Game and editor.

## Requirements

* [The Meson Build System](https://github.com/mesonbuild/meson)
* [SDL3](https://libsdl.org/)
* An OpenGL loader: Extremely likely to be provided by your OS or GPU drivers

## Cloning

Run the following command

```shell
git clone --depth 1 https://github.com/XenoBino/2d-game.git
```

## Building

Run the following command

```shell
# For windows
scripts/build.bat

# For POSIX (Linux, BSD, MacOS and all Unix's)
scripts/build.sh
```

## Contributing

### Over HTTPs

Navigate to [settings](https://github.com/settings/tokens) and create a classic token with the `repo` scope.
Then when pushing, enter the token instead of your password.

### Over SSH

Please follow the [official github guide](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/about-ssh).
