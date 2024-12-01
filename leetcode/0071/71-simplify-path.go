//go:build ignore

package main

import (
	"strings"
)

func simplifyPath(path string) string {
	tokens := strings.Split(path, "/")
	var pathTokens = []string{}

	for _, token := range tokens {
		switch token {
		case ".", "":
			continue
		case "..":
			if len(pathTokens) > 0 {
				pathTokens = pathTokens[:len(pathTokens)-1]
			}
			continue
		default:
			pathTokens = append(pathTokens, token)
		}
	}

	return "/" + strings.Join(pathTokens, "/")
}

