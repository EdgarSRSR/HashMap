# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.HashMap.Debug:
/Users/edgarsr/Documents/hashmap/build-xcode/Debug/HashMap:
	/bin/rm -f /Users/edgarsr/Documents/hashmap/build-xcode/Debug/HashMap


PostBuild.HashMap.Release:
/Users/edgarsr/Documents/hashmap/build-xcode/Release/HashMap:
	/bin/rm -f /Users/edgarsr/Documents/hashmap/build-xcode/Release/HashMap


PostBuild.HashMap.MinSizeRel:
/Users/edgarsr/Documents/hashmap/build-xcode/MinSizeRel/HashMap:
	/bin/rm -f /Users/edgarsr/Documents/hashmap/build-xcode/MinSizeRel/HashMap


PostBuild.HashMap.RelWithDebInfo:
/Users/edgarsr/Documents/hashmap/build-xcode/RelWithDebInfo/HashMap:
	/bin/rm -f /Users/edgarsr/Documents/hashmap/build-xcode/RelWithDebInfo/HashMap




# For each target create a dummy ruleso the target does not have to exist
