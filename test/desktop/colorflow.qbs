import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: false

    Depends { name:"cpp" }
    cpp.debugInformation: true

    cpp.includePaths: [
            "../../src/",
        ]

    Group {
            name: "Application"
            prefix: "./"
            files: [
                "*.c",
                "*.cpp",
                "*.h",
            ]
    }
    Group {
        name: "ColorFlow"
        prefix: "../../src/"
        files: [
            "*.c",
            "*.cpp",
            "*.h",
        ]
    }
}

