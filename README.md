# network-display
This is a suite of tools to send messages across the LAN to the
Pi-based LCD screen, and display them on the screen when they arrive.

_HOWEVER_, this is intended to demonstrate the concept of what a
security problem is, and therefore shouldn't be used in any kind
of live environment, as there's a security issue in the design,
which I'm leaving in place for expository purposes.

Eventually I want to write a series of blog posts [at my
blog](https://uselessofblog.blogspot.co.uk/) explaining what the
problem is, what to do about it, and why I bothered.

The server code is Linux-specific, sorry about that. I may see if 
I can make it work on a Mac as well. I don't have a Windows
development machine, so there won't be a Windows version.

The server should probably background itself, but I haven't done
this yet, because I'm still iterating it and it's kind of handy
not to have to find the pid and kill it each time. Bleh.

The code should probably do more error-checking. And by 'more', I
actually mean 'any'. Oh well, like I said, this isn't a good example
of anything, really.

## Client

I haven't bothered writing a client - you can use NetCat like this:
```
% echo -n "hello" | nc -4u -w 4 xxx.xxx.xxx.xxx 7991
```

