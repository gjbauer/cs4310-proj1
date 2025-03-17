#!/usr/bin/perl
use 5.16.0;
use warnings FATAL => 'all';
use POSIX ":sys_wait_h";

use Time::HiRes qw(time);
use Test::Simple tests => 14;

my @BINS = qw(collatz-ivec-hwx collatz-ivec-sys
              collatz-list-hwx collatz-list-sys
              collatz-ivec-opt collatz-list-opt
              frag-hwx frag-opt frag-sys);
my @OBJS = glob("*.o");
my @BADS = (@BINS, @OBJS);
my $unclean = 0;
for my $file (@BADS) {
    if (-e "$file") {
        say("# UNCLEAN! Found $file");
        $unclean = 1;
    }
}
ok(!$unclean, "no binaries");

system("(make 2>&1) > /dev/null");

sub csum_check {
    my ($file, $expect) = @_;
    my ($csum, undef) = split(/\s+/, `b2sum -l 64 $file`);
    unless ($csum eq $expect) {
        die "file modified: $file";
    }
}

csum_check("ivec_main.c", "fa72b031c2ca3ded");
csum_check("list_main.c", "b45f5d3ec8cf8bf3");
csum_check("frag_main.c", "c716c792e4f658ce");

sub get_time {
    my $data = `cat time.tmp | grep ^real`;
    $data =~ /^real\s+(.*)$/;
    return 0 + $1;
}

sub run_prog {
    my ($prog, $arg) = @_;
    system("rm -f outp.tmp time.tmp");
    system("timeout -k 30 20 time -p -o time.tmp ./$prog $arg > outp.tmp");
    return `cat outp.tmp`;
}

ok(-f "report.txt" && !-x "report.txt", "report.txt exists and isn't executable");
ok(-f "graph.png" && !-x "graph.png", "graph.png exists and isn't executable");

my $sys_v = run_prog("collatz-ivec-sys", 1000);
ok($sys_v =~ /at 871: 178 steps/, "ivec-sys 1k");

my $sys_l = run_prog("collatz-list-sys", 1000);
ok($sys_l =~ /at 871: 178 steps/, "list-sys 1k");

my $hw7_l = run_prog("collatz-list-hwx", 100);
ok($hw7_l =~ /at 97: 118 steps/, "list-hwx 100");

my $hw7_v = run_prog("collatz-ivec-hwx", 100);
ok($hw7_v =~ /at 97: 118 steps/, "ivec-hwx 100");

my $par_v = run_prog("collatz-ivec-opt", 1000);
my $pv_ok = $par_v =~ /at 871: 178 steps/;
ok($pv_ok, "ivec-par 1k");

my $par_l = run_prog("collatz-list-opt", 1000);
my $pl_ok = $par_l =~ /at 871: 178 steps/;
ok($pl_ok, "list-par 1k");

$par_v = run_prog("collatz-ivec-opt", 10000);
$pv_ok = $par_v =~ /at 6171: 261 steps/;
ok($pv_ok, "ivec-opt 10k");

$par_l = run_prog("collatz-list-opt", 10000);
$pl_ok = $par_l =~ /at 6171: 261 steps/;
ok($pl_ok, "list-opt 10k");

$par_v = run_prog("collatz-ivec-opt", 500000);
$pv_ok = $par_v =~ /at 410011: 448 steps/;
ok($pv_ok, "ivec-opt 500k");

$par_l = run_prog("collatz-list-opt", 500000);
$pl_ok = $par_l =~ /at 410011: 448 steps/;
ok($pl_ok, "list-opt 500k");

my $fragt = run_prog("frag-opt", 1);
my $ft_ok = $fragt =~ /frag test ok/;
ok($ft_ok, "fragmentation test");

system("(make clean 2>&1) > /dev/null");
