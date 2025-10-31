#include <taskflow/taskflow.hpp>

int main() {
    tf::Executor executor;

    tf::AsyncTask A = executor.silent_dependent_async([]() {
        printf("A\n");
    });

    tf::AsyncTask B = executor.silent_dependent_async([]() {
        printf("B\n");
    }, A);

    tf::AsyncTask C = executor.silent_dependent_async([]() {
        printf("C\n");
    }, A);

    auto [D, fuD] = executor.dependent_async([]() {
        printf("D\n");
    }, B, C);

    // Wait for D to finish, which in turn means A, B, and C have finished
    fuD.get();
}
